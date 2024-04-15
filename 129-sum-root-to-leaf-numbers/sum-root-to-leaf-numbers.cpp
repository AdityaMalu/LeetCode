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

    int preorder(TreeNode* node, int &sum, string str)
    {
        if(node->left == nullptr && node->right == nullptr){
            str += to_string(node->val);
            sum += stoi(str); 
            return sum;
        }
        str += to_string(node->val);
        if (node->left)
        int left = preorder(node->left, sum, str);
        if(node->right)
        int right = preorder(node->right, sum, str);

        return sum;

    }
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        preorder(root,sum,"");
        return sum;
    }
};