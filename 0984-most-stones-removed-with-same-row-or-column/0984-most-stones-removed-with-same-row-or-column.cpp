class Solution {
public:
    void dfs(unordered_map<int, vector<int>> &adj, vector<int>&vis, int ind) {
        vis[ind] = 1;
        for (int i : adj[ind]) {
            if (vis[i] == 0) {
                dfs(adj, vis, i);
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < stones.size(); i++) {
            for (int j = i + 1; j < stones.size(); j++) {
                if (stones[i][0] == stones[j][0] ||
                    stones[i][1] == stones[j][1]) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> vis(stones.size(), 0);
        int com = 0;

        for (int i = 0; i < stones.size(); i++) {
            if (vis[i] == 0) {
                dfs(adj, vis, i);
                com++;
            }
        }

        return stones.size() - com;
    }
};