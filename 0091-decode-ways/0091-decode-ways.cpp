class Solution {
public:
    int recc(string s,int ind,vector<int> &dp){
        if(ind == s.size()){
            return 1;
        }

        if(s[ind] == '0'){
            return 0;
        }

        if(dp[ind] != -1){
            return dp[ind];
        }

        int one = recc(s,ind+1,dp);
        int two = 0;
        if(ind + 1 < s.size() && (s[ind] == '1' || (s[ind] == '2' && s[ind+1] < '7'))){
            two = recc(s,ind+2,dp);
        }

        return dp[ind] = one+two;
    }
    int numDecodings(string s) {
        vector<int> dp(s.size()+1,-1);
        return recc(s,0,dp);
    }
};