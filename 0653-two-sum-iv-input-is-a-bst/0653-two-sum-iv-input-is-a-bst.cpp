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
    TreeNode* findMin(TreeNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    TreeNode* findMax(TreeNode* node) {
        while (node->right != nullptr) {
            node = node->right;
        }
        return node;
    }

    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* successor = nullptr;
        while (root != nullptr) {
            if (p->val < root->val) {
                successor = root;
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return successor;
    }

    TreeNode* inorderPredecessor(TreeNode* root, TreeNode* p) {
        TreeNode* predecessor = nullptr;
        while (root != nullptr) {
            if (p->val > root->val) {
                predecessor = root;
                root = root->right;
            } else {
                root = root->left;
            }
        }
        return predecessor;
    }

    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;

        TreeNode* left = findMin(root);
        TreeNode* right = findMax(root);

        while (left != right) {
            int sum = left->val + right->val;
            if (sum == k) {
                return true;
            } else if (sum < k) {
                left = inorderSuccessor(root, left);
            } else {
                right = inorderPredecessor(root, right);
            }
        }

        return false;
    }
};
