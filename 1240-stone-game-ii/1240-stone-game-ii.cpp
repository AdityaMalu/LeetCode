class Solution {
public:
    int n;
    int recc(int ind, int m, bool isAlice, vector<int> &piles,vector<vector<vector<int>>> &dp){

        if(ind >= n){
            return 0;
        }

        if(dp[ind][m][isAlice] != -1) return dp[ind][m][isAlice];

        int ans=0;
        if(isAlice) ans = INT_MIN;
        else ans = INT_MAX;

        int sum = 0;
        for(int i = 1 ; i <= min(2*m , n-ind) ; i++){
            sum+= piles[ind+i-1];
            if(isAlice){
                ans = max(ans, sum + recc(ind+i, max(m,i) , !isAlice , piles,dp));
            }
            else{
                ans = min(ans, recc(ind+i,max(m,i) , !isAlice, piles,dp));
            }
        }

        return  dp[ind][m][isAlice] = ans;
    }


    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        vector<vector<vector<int>>> dp(102, vector<vector<int>>(102, vector<int>(2, -1)));
        return recc(0,1,1,piles,dp);
    }
};