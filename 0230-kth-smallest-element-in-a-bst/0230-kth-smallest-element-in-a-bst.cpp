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
    void inorder(TreeNode* root, int &counter, int &ksmall, int k){
        if(!root || counter >= k) return;
        inorder(root->left,counter,ksmall,k);
        counter++;
        if(counter == k){
            ksmall = root->val;
        }
        inorder(root->right,counter,ksmall,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0,ksmall = 0;
        inorder(root,cnt,ksmall,k);
        return ksmall;

    }
};