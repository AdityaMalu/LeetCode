class Solution {
public:
    void bfs(vector<vector<int>>& heights, vector<vector<int>>& vis, queue<pair<int, int>>& q) {
        int m = heights.size();
        int n = heights[0].size();
        int drow[] = {0, 1, -1, 0};
        int dcol[] = {-1, 0, 0, 1};
        
        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();
            
            for (int i = 0; i < 4; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                
                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && !vis[nrow][ncol] &&
                    heights[nrow][ncol] >= heights[row][col]) {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> pacific(m, vector<int>(n, 0));
        vector<vector<int>> atlantic(m, vector<int>(n, 0));
        queue<pair<int, int>> pacificQueue, atlanticQueue;
        
        for (int i = 0; i < m; i++) {
            pacificQueue.push({i, 0});
            atlanticQueue.push({i, n - 1});
            pacific[i][0] = 1;
            atlantic[i][n - 1] = 1;
        }
        for (int j = 0; j < n; j++) {
            pacificQueue.push({0, j});
            atlanticQueue.push({m - 1, j});
            pacific[0][j] = 1;
            atlantic[m - 1][j] = 1;
        }
        
        bfs(heights, pacific, pacificQueue);
        bfs(heights, atlantic, atlanticQueue);
        
        vector<vector<int>> result;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        
        return result;
    }
};
