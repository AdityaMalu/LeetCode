class Solution {
public:
    int dfs(int i, unordered_map<int, vector<int>>& mp, vector<int>& quiet, vector<int>& ans, vector<int>& vis) {
        if (vis[i]) {
            return ans[i];
        }

        vis[i] = 1;
        ans[i] = i; // Initialize the answer for this node to itself
        for (auto it : mp[i]) {
            int c = dfs(it, mp, quiet, ans, vis);
            if (quiet[c] < quiet[ans[i]]) {
                ans[i] = c;
            }
        }

        return ans[i];
    }

    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        unordered_map<int, vector<int>> mp;

        // Build the graph
        for (auto& r : richer) {
            mp[r[1]].push_back(r[0]);
        }

        vector<int> ans(n, -1);
        vector<int> vis(n, 0);

        // Run DFS for each node
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, mp, quiet, ans, vis);
            }
        }

        return ans;
    }
};
