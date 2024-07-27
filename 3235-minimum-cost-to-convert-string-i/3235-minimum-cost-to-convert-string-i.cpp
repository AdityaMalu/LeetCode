class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        if (source.length() != target.length()) return -1;

        const int INF = 1e9;
        vector<vector<long long>> adj(26, vector<long long>(26, INF));

        for (int i = 0; i < 26; i++) {
            adj[i][i] = 0;
        }

        for (int i = 0; i < original.size(); i++) {
            int from = original[i] - 'a';
            int to = changed[i] - 'a';
            adj[from][to] = min(adj[from][to], (long long)cost[i]);
        }

        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (adj[i][k] < INF && adj[k][j] < INF) {
                        adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                    }
                }
            }
        }

        long long ans = 0;
        for (int i = 0; i < source.size(); i++) {
            int from = source[i] - 'a';
            int to = target[i] - 'a';
            if (adj[from][to] == INF) return -1;
            ans += adj[from][to];
        }

        return ans;
    }
};