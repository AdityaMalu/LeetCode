class Solution {
public:

    int recc(string text1, string text2, int ind1,int ind2,vector<vector<int>> &dp){
        if(ind1<0 || ind2<0){
            return 0;
        }

        if(dp[ind1][ind2] != -1){
            return dp[ind1][ind2];
        }
        if(text1[ind1] == text2[ind2]){
            return dp[ind1][ind2] = 1+ recc(text1,text2,ind1-1,ind2-1,dp);
        }
        else{
            return dp[ind1][ind2] = max(recc(text1,text2,ind1-1,ind2,dp),recc(text1,text2,ind1,ind2-1,dp));
        }
        
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1,0));

        for(int i = 1 ; i< text1.size()+1 ; i++){
            for(int j = 1 ; j < text2.size()+1 ; j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        return dp[text1.size()][text2.size()];
        
        return recc(text1,text2,text1.size()-1,text2.size()-1,dp);
    }
};