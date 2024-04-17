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

    void smallest(TreeNode* node, string &ans, string path){

        if(node == nullptr) return;

        path += char('a' + node->val);  
        if(node->left == nullptr && node->right == nullptr){
            reverse(path.begin(), path.end());
            if(ans.empty() || path<ans){
                ans = path;
            }
            reverse(path.begin(),path.end());
        }
        if(node->left)
        smallest(node->left,ans,path);
        if(node->right)
        smallest(node->right,ans,path);
    }
    string smallestFromLeaf(TreeNode* root) {
        string ans = "",path;
        smallest(root,ans,path);
        return ans;

    }
};