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
    void inorder(TreeNode* root, vector<int> &trav){
        if (!root) return;

        inorder(root->left, trav);
        trav.push_back(root->val);
        inorder(root->right , trav);

    }
    int getMinimumDifference(TreeNode* root) {

        vector<int> trav;
        inorder(root,trav);
        int ans = 1e6;
        for(int i = 1 ; i < trav.size() ; i++){
            ans = min(ans,(trav[i] - trav[i-1]));
        }
        return ans;
        
    }
};