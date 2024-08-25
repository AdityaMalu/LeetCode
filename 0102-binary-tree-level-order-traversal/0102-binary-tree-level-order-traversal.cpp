/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> ans;

        if (!root)
            return ans;
        map<int, vector<int>> mp;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            auto curr = q.front();
            TreeNode* node = curr.first;
            int lvl = curr.second;
            q.pop();

            if (mp.find(lvl) == mp.end()) {
                mp[lvl] = {node->val};
            } else {
                mp[lvl].push_back(node->val);
            }

            if (node->left) {
                q.push({node->left, lvl + 1});
            }
            if (node->right) {
                q.push({node->right, lvl + 1});
            }
        }

        for (auto i : mp) {
            ans.push_back(i.second);
        }

        // reverse(ans.begin(), ans.end());
        return ans;
    }
};