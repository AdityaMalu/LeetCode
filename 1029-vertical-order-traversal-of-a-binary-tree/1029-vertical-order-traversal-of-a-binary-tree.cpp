/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;

        queue<pair<TreeNode*, pair<int, int>>> q;
        map<int, map<int, multiset<int>>> nodes;

        q.push({root, {0, 0}});

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            TreeNode* node = curr.first;
            int col = curr.second.first;
            int row = curr.second.second;

            nodes[col][row].insert(node->val);

            if (node->left) {
                q.push({node->left, {col - 1, row + 1}});
            }
            if (node->right) {
                q.push({node->right, {col + 1, row + 1}});
            }
        }

        for (auto& col_pair : nodes) {
            vector<int> col_nodes;
            for (auto& row_pair : col_pair.second) {
                col_nodes.insert(col_nodes.end(), row_pair.second.begin(), row_pair.second.end());
            }
            ans.push_back(col_nodes);
        }

        return ans;
    }
};
