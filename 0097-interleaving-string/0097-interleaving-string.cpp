class Solution {
public:
    bool recc(string &s1, int ind1, string &s2, int ind2,string &s3,int ind3,vector<vector<int>> &dp){
        if(ind3 == s3.size()) return true;
        
        bool ans = false;

        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        if(ind1 < s1.size() && s1[ind1] == s3[ind3]){
            ans = ans | recc(s1,ind1+1,s2,ind2,s3,ind3+1,dp);
        }

        if(ind2 < s2.size() && s2[ind2] == s3[ind3]){
            ans = ans | recc(s1,ind1,s2,ind2+1,s3,ind3+1,dp);
        }

        return dp[ind1][ind2] = ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()) return false;
        vector<vector<int>> dp(s3.size(),vector<int>(s3.size(),-1));
        return recc(s1,0,s2,0,s3,0,dp);
    }
};