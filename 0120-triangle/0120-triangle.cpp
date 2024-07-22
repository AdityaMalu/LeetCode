class Solution {
public:
    int recc(vector<vector<int>>& triangle, int ind, int row,vector<vector<int>> &dp){
        if(row == triangle.size()-1){
            return triangle[row][ind];
        }

        if(dp[row][ind] != -1){
            return dp[row][ind];
        }

        int take = triangle[row][ind] + min(recc(triangle,ind,row+1,dp) , recc(triangle,ind+1,row+1,dp));
        int not_take = triangle[row][ind] + recc(triangle,ind,row+1,dp);
       

        return dp[row][ind] = min(not_take,take);
    }
    int minimumTotal(vector<vector<int>>& triangle) {

        vector<vector<int>> dp(triangle.size(),vector<int>(triangle.size(),-1));
        return recc(triangle,0,0,dp);
        
    }
};