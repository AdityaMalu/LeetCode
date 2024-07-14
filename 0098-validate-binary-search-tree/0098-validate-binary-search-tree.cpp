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
    bool isvalid(TreeNode* root, long long l,long long r){
        if(!root){
            return true;
        }
        if(root->val < r && root->val > l){
            return isvalid(root->left,l,root->val) && isvalid(root->right,root->val,r);
        }
        return false;
    }
    bool isValidBST(TreeNode* root) {
        return isvalid(root,-1e14,1e14);
    }
};