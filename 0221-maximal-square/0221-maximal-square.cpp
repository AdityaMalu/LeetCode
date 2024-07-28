class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size() < 1) return 0;

        int row = matrix.size();
        int col = matrix[0].size();

        vector<vector<int>> dp(row+1,vector<int>(col+1,0));
        int ans = 0;
        for(int r = 0 ; r < row ; r++){
            for(int c = 0 ; c < col ; c++){
                if(matrix[r][c] == '1'){
                    dp[r+1][c+1] = min(dp[r][c], min(dp[r+1][c] , dp[r][c+1])) +1;
                    ans = max(ans,dp[r+1][c+1]);
                }
            }
        }
        return pow(ans,2);
    }
};