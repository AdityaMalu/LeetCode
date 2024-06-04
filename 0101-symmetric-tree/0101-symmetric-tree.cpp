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

    bool check(TreeNode* leftroot, TreeNode* rightroot){
        if(leftroot == nullptr && rightroot == nullptr){
            return true;
        }
        if(leftroot == nullptr || rightroot == nullptr){
            return false;
        }
        if(leftroot->val != rightroot->val){
            return false;
        }
        return(check(leftroot->left , rightroot->right) && check(leftroot->right, rightroot->left));
    }
    bool isSymmetric(TreeNode* root) {
        if(!root){
            return true;
        }
        return check(root->right,root->left);
    }
};