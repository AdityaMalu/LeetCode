/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     long long val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(long long x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(long long x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        long long ans = 0;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        while(!q.empty()){
            long long size = q.size();
            long long minn = q.front().second;

            long long first,last;
            for(long long i = 0 ; i< size ; i++){
                TreeNode* node = q.front().first;
                long long curr_id = q.front().second - minn;
                q.pop();
                if(i == 0) first = curr_id;
                if(i == size-1) last = curr_id;
                if(node->left){
                    q.push({node->left,2*curr_id+1});
                }
                if(node->right){
                    q.push({node->right,2*curr_id+2});
                }
            }
            ans = max(ans, last-first+1);
        }
        return ans;
    }
};