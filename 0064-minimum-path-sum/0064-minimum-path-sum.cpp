class Solution {
public:
    int rec(vector<vector<int>> &grid, int row, int col,vector<vector<int>> &dp){
        if (row == grid.size() - 1 && col == grid[0].size() - 1) {
            return grid[row][col];
        }
        if (row >= grid.size() || col >= grid[0].size()) {
            return INT_MAX;
        }

        if(dp[row][col] != -1){
            return dp[row][col];
        }

        int right = rec(grid,row,col+1,dp);
        int down = rec(grid,row+1,col,dp);

        return dp[row][col] = grid[row][col] + min(right,down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
        return rec(grid,0,0,dp);
    }
};