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
    int trav(TreeNode* root,int &val){
        if(!root){
            return 0;
        }

        int left = max(0,trav(root->left,val));
        int right = max(0,trav(root->right,val));

        int curr = root->val+left+right;

        val  = max(curr,val);

        return root->val+ max(left,right);
    }

    int maxPathSum(TreeNode* root) {
        int val = INT_MIN;
        trav(root,val);
        return val;
    }
};