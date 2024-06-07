/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int height(Node *root) {
        if (!root) {
            return 0;
        }

        int max_child_height = 0;
        for (auto child : root->children) {
            max_child_height = max(max_child_height, height(child));
        }

        return max_child_height + 1;
    }

    int maxDepth(Node* root) {
        return height(root);
    }
};