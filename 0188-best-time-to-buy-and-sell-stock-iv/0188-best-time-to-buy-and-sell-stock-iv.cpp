class Solution {
public:
    int recc(vector<int>& prices, int ind, bool holding, int transactions, vector<vector<vector<int>>>& memo,int k) {
        if (ind == prices.size() || transactions == k) return 0;
        if (memo[ind][holding][transactions] != -1) return memo[ind][holding][transactions];

        int doNothing = recc(prices, ind + 1, holding, transactions, memo,k);
        if (holding) {
            int sell = prices[ind] + recc(prices, ind + 1, false, transactions + 1, memo,k);
            memo[ind][holding][transactions] = max(doNothing, sell);
        } else {
            int buy = -prices[ind] + recc(prices, ind + 1, true, transactions, memo,k);
            memo[ind][holding][transactions] = max(doNothing, buy);
        }

        return memo[ind][holding][transactions];
    }

    int maxProfit(int k, vector<int>& prices) {

        // if(prices.empty()) return 0;
        
        // int n = prices.size();
        
        // vector<vector<vector<int>>> dp(n, vector<vector<int>>(3, vector<int>(2, 0)));
        
        // dp[0][0][0] = 0; 
        // dp[0][0][1] = -prices[0];
        
        // dp[0][1][0] = 0; 
        // dp[0][1][1] = -prices[0]; 
        
        // dp[0][2][0] = 0; 
        // dp[0][2][1] = -prices[0];
        
        // for(int i = 1; i < n; i++) {
        //     dp[i][0][0] = dp[i-1][0][0];
        //     dp[i][0][1] = max(dp[i-1][0][1], dp[i-1][0][0] - prices[i]);
            
        //     dp[i][1][0] = max(dp[i-1][1][0], dp[i-1][0][1] + prices[i]);
        //     dp[i][1][1] = max(dp[i-1][1][1], dp[i-1][1][0] - prices[i]);
            
        //     dp[i][2][0] = max(dp[i-1][2][0], dp[i-1][1][1] + prices[i]);
        //     dp[i][2][1] = max(dp[i-1][2][1], dp[i-1][2][0] - prices[i]);
        // }
        
        // return max(dp[n-1][1][0], dp[n-1][2][0]);
        
        vector<vector<vector<int>>> memo(prices.size(), vector<vector<int>>(2, vector<int>(k, -1)));
        return recc(prices, 0, false, 0, memo,k);
    }
};
