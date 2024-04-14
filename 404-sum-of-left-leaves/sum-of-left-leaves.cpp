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
    int sumOfLeftLeaves(TreeNode* root) {
       if(!root)
       return 0;

       queue<pair<TreeNode*,bool>>q;
       q.push({root,false});
       int ans = 0;
       while(!q.empty()){
        auto [node,isleft] = q.front();
        q.pop();

        if(isleft && !node->left && !node->right){
            ans+=node->val;
        }
        if(node->left){
            q.push({node->left,true});
        }
        if(node->right){
            q.push({node->right , false});
        }
       }
       return ans;
    }
};