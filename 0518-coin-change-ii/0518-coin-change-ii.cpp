class Solution {
public:
    int recc(vector<int> &coins, int ind, int amount,vector<vector<int>> &dp) {
        if (amount == 0) return 1;
        if (ind < 0 || amount < 0) return 0;


        if(dp[ind][amount] != -1) return dp[ind][amount];
        int not_take = recc(coins, ind - 1, amount,dp);
        int take = 0;
        if (amount >= coins[ind]) {
            take = recc(coins, ind, amount - coins[ind],dp);
        }

        return dp[ind][amount] = not_take + take;
    }
    
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        return recc(coins, coins.size() - 1, amount,dp);
    }
};