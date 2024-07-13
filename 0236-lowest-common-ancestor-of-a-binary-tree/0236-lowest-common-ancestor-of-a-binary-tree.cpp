#include <vector>
#include <unordered_map>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool findPath(TreeNode* root, TreeNode* target, vector<TreeNode*>& path) {
        if (!root) return false;

        path.push_back(root);

        if (root == target) return true;

        if (findPath(root->left, target, path) || findPath(root->right, target, path)) {
            return true;
        }

        path.pop_back();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1, path2;

        findPath(root, p, path1);
        findPath(root, q, path2);

        int minLength = min(path1.size(), path2.size());
        TreeNode* lca = nullptr;

        for (int i = 0; i < minLength; ++i) {
            if (path1[i] == path2[i]) {
                lca = path1[i];
            } else {
                break;
            }
        }

        return lca;
    }
};
