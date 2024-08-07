class Solution {
public:
    
    int recc(string &word1, int ind1 , string &word2 , int ind2,vector<vector<int>> &dp){
        if(ind1 <0){
            return ind2+1;
        }
        if(ind2<0){
            return ind1+1;
        }

        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        if(word1[ind1] == word2[ind2]){
            return dp[ind1][ind2] =  recc(word1,ind1-1,word2,ind2-1,dp);
        }
        else{
            return dp[ind1][ind2] =  1 + min(recc(word1,ind1-1,word2,ind2-1,dp),min(recc(word1,ind1-1,word2,ind2,dp) ,recc(word1,ind1 , word2,ind2-1,dp)));
        }



    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size(),vector<int>(word2.size(),-1));
        return recc(word1,word1.size()-1, word2 , word2.size()-1,dp);
    }
};