class Solution {
public:

    int rec(vector<vector<int>>& matrix, int row, int col, vector<vector<int>>& memo){
        if(col < 0 || col >= matrix[0].size()){
            return INT_MAX;
        }
        if(row == matrix.size() - 1){
            return matrix[row][col];
        }
        if(memo[row][col] != INT_MAX){
            return memo[row][col];
        }
        
        int down = rec(matrix, row + 1, col, memo);
        int rd = rec(matrix, row + 1, col + 1, memo);
        int ld = rec(matrix, row + 1, col - 1, memo);
        
        memo[row][col] = matrix[row][col] + min(down, min(rd, ld));
        return memo[row][col];
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int minSum = INT_MAX;
        vector<vector<int>> memo(n, vector<int>(n, INT_MAX));
        
        for(int col = 0; col < n; ++col){
            minSum = min(minSum, rec(matrix, 0, col, memo));
        }
        return minSum;
    }
};