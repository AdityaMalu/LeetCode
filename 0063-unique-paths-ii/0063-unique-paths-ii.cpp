class Solution {
public:
    int recc(vector<vector<int>> &grid, int row, int col, vector<vector<int>> &dp){
        if(row >= grid.size() || col >= grid[0].size() || grid[row][col] == 1) return 0;
        
        if(row == grid.size() - 1 && col == grid[0].size() - 1) return 1;

        if(dp[row][col] != -1) return dp[row][col];

        int right = recc(grid, row, col + 1, dp);
        int down = recc(grid, row + 1, col, dp);

        return dp[row][col] = right + down;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        
        if(obstacleGrid[0][0] == 1 || obstacleGrid[row - 1][col - 1] == 1) return 0;
        
        vector<vector<int>> dp(row, vector<int>(col, -1));
        
        return recc(obstacleGrid, 0, 0, dp);
    }
};
