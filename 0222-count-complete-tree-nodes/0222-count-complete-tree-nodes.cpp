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

    int dfs(TreeNode* root){
        if (!root) return 0;
        return 1+dfs(root->left);
    }
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int  dl = dfs(root->left);
        int dr = dfs(root->right);

        int ans = pow(2,dr);

        if(dl == dr) return ans + countNodes(root->right);
        else return ans + countNodes(root->left);
    }
};