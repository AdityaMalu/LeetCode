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
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),0));

        for(int i = 0; i < grid.size() ; i++){
            for(int j = 0; j<grid[0].size() ; j++){
                if (i == 0 && j == 0)
                dp[i][j] = grid[i][j]; 
            else {

                int up = grid[i][j];
                if (i > 0)
                    up += dp[i - 1][j]; 
                else
                    up += 1e9; 

                int left = grid[i][j];
                if (j > 0)
                    left += dp[i][j - 1]; 
                else
                    left += 1e9; 

                dp[i][j] = min(up, left);
            }
            }
        }
        return dp[grid.size()-1][grid[0].size()-1];
        return rec(grid,0,0,dp);
    }
};