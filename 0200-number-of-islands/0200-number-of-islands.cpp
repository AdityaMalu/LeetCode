#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    void bfs(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& vis) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;
        q.push({i, j});
        vis[i][j] = true;

        vector<int> drow = {0, 0, 1, -1};
        vector<int> dcol = {1, -1, 0, 0};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int k = 0; k < 4; ++k) {
                int newRow = r + drow[k];
                int newCol = c + dcol[k];

                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols &&
                    grid[newRow][newCol] == '1' && !vis[newRow][newCol]) {
                    vis[newRow][newCol] = true;
                    q.push({newRow, newCol});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> vis(rows, vector<bool>(cols, false));
        int numIslands = 0;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    ++numIslands;
                    bfs(grid, i, j, vis);
                }
            }
        }

        return numIslands;
    }
};
