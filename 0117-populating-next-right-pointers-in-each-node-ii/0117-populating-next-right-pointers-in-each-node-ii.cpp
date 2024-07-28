class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;

        queue<pair<Node*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            Node* curr = q.front().first;
            int lvl = q.front().second;
            q.pop();

            if (curr->left) q.push({curr->left, lvl + 1});
            if (curr->right) q.push({curr->right, lvl + 1});

            if (!q.empty() && q.front().second == lvl) {
                curr->next = q.front().first;
            } else {
                curr->next = nullptr;
            }
        }

        return root;
    }
};