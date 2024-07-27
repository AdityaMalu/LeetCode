class Solution {
public:
    int recc(vector<int>& prices, int ind, bool holding, int transactions, vector<vector<vector<int>>>& memo) {
        if (ind == prices.size() || transactions == 2) return 0;
        if (memo[ind][holding][transactions] != -1) return memo[ind][holding][transactions];

        int doNothing = recc(prices, ind + 1, holding, transactions, memo);
        if (holding) {
            int sell = prices[ind] + recc(prices, ind + 1, false, transactions + 1, memo);
            memo[ind][holding][transactions] = max(doNothing, sell);
        } else {
            int buy = -prices[ind] + recc(prices, ind + 1, true, transactions, memo);
            memo[ind][holding][transactions] = max(doNothing, buy);
        }

        return memo[ind][holding][transactions];
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> memo(prices.size(), vector<vector<int>>(2, vector<int>(2, -1)));
        return recc(prices, 0, false, 0, memo);
    }
};
