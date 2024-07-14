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
    void pre(TreeNode* root,vector<int> &res){
        if(!root){
            res.push_back(INT_MIN);
            return; 
        }
        res.push_back(root->val);
        pre(root->left,res);
        pre(root->right,res);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> one,two;
        pre(p,one);
        pre(q,two);
        return one==two;
    }
};