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
    int ans = INT_MIN;
    vector<int> trav(TreeNode* root){
        if(!root){
            return {INT_MAX,INT_MIN,0};
        }
        vector<int> leftt = trav(root->left);
        vector<int> rightt = trav(root->right);

        int val = root->val;

        if(!(val > leftt[1] && val < rightt[0])){return {INT_MIN,INT_MAX,0};}
        ans = max(ans,leftt[2]+rightt[2]+val);
        return {min(root->val,leftt[0]),max(rightt[1],root->val),leftt[2]+rightt[2]+val};
    }


    int maxSumBST(TreeNode* root) {
        vector<int>ansi = trav(root);
        if(ans < 0) return 0;
        return ans;
        
    }
};