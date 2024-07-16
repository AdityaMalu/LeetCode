class Solution {
public:
    int rec(vector<int>& coins, int amount,int ind,vector<int> &dp){
        if(amount == 0){
            
        }

        if(amount < 0 || ind < 0){
            return INT_MAX;
        }

        int not_take = rec(coins,amount,ind-1,dp);
        int take = INT_MAX;
        if(amount > 0 || ind > 0){
            take = rec(coins,amount-coins[ind],ind,dp);
            if (take != INT_MAX){
                take++;
            }
        }

        return min(take,not_take);

    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (int coin : coins) {
                if (i - coin >= 0 && dp[i - coin] != INT_MAX) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];

        if (rec(coins,amount,coins.size()-1,dp) == INT_MAX) return -1;
        return rec(coins,amount,coins.size()-1,dp);
    }
};