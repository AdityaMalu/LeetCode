class Solution {
public:
    bool dfs(vector<vector<int>> &grid1, vector<vector<int>> &grid2,
             vector<vector<int>> &vis, int r, int c) {
        vis[r][c] = 1;

        vector<int> drow = {0, 0, 1, -1};
        vector<int> dcol = {1, -1, 0, 0};

        bool ans = true;

        if (grid2[r][c] == 1 && grid1[r][c] == 0) {
            ans = false;
        }

        for (int i = 0; i < 4; i++) {
            int nr = r + drow[i];
            int nc = c + dcol[i];

            if (nr >= 0 && nc >= 0 && nr < grid2.size() &&
                nc < grid2[0].size() && !vis[nr][nc] &&
                grid2[nr][nc] == 1) {
                ans &= dfs(grid1, grid2, vis, nr, nc);
            }
        }

        return ans;
    }

    int countSubIslands(vector<vector<int>>& grid1,
                        vector<vector<int>>& grid2) {
        vector<vector<int>> vis(grid2.size(), vector<int>(grid2[0].size(), 0));
        int ans = 0;

        for (int i = 0; i < grid2.size(); i++) {
            for (int j = 0; j < grid2[0].size(); j++) {
                if (grid2[i][j] == 1 && !vis[i][j]) {
                    if (dfs(grid1, grid2, vis, i, j)) {
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};
