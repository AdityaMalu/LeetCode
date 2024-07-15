class Solution {
public:
    int recur(string &word1,string &word2, int ind1, int ind2,vector<vector<int>> &dp){
        if(ind1 < 0){
            return ind2+1;
        }
        if(ind2<0){
            return ind1+1;
        }

        if(dp[ind1][ind2] != -1){
            return dp[ind1][ind2];
        }

        if(word1[ind1] == word2[ind2]){
           return recur(word1,word2,ind1-1,ind2-1,dp);
        }
        else{
            return dp[ind1][ind2] = 1 + min(recur(word1,word2,ind1-1,ind2,dp),min(recur(word1,word2,ind1,ind2-1,dp),recur(word1,word2,ind1-1,ind2-1,dp)));
        }
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.size()+1,vector<int>(word2.size()+1,0));

        for(int i = 0 ; i <= word1.size() ; i++){
            dp[i][0] = i;
        }

        for(int i = 0 ; i <= word2.size() ; i++){
            dp[0][i] = i;
        }

        for(int i = 1 ; i<=word1.size() ; i++){
            for(int j = 1 ; j <= word2.size() ; j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = 1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
                }
            }
        }

        return dp[word1.size()][word2.size()];
        return recur(word1,word2,word1.size()-1,word2.size()-1,dp);
    }
};