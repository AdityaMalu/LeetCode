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
     TreeNode* inorder(TreeNode* node, int height, int val, int depth){
        if(height == depth-2){
            TreeNode* left = node->left;
            TreeNode* right = node->right;
            node->left = new TreeNode(val);
            node->right = new TreeNode(val);
            node->left->left = left;
            node->right->right = right;
            // cout<<node->val<<"value"<<endl;
            return node;
        }
        // cout<<height<<"height"<<" ";
        // height += 1;
        if(node->left){
            TreeNode* left = inorder(node->left,height+1,val,depth);
        }
        if(node->right){
            TreeNode* right = inorder(node->right,height+1,val,depth);
        }
        // height-=1;
        return node;


    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1){
            TreeNode* newNode = new TreeNode(val);
            newNode->left = root;
            return newNode;
        }
        TreeNode* root1;
        int height = 0;
        root1 = inorder(root,height,val,depth);
        return root1;
    }
};