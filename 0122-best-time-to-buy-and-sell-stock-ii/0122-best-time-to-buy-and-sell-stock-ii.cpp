class Solution {
public:

    int recc(vector<int> &prices , int ind,int curr,vector<int> &dp){
        if(ind  ==  prices.size()-1){
            if(prices[ind] >= curr) return prices[ind] - curr;
            else return 0;
        }

        if(dp[ind] != -1){
            return dp[ind];
        }
        int sell;
        if(prices[ind] <= curr){
            recc(prices,ind+1,prices[ind],dp);
        }
        else{
            sell = prices[ind] - curr + max(recc(prices,ind+1,prices[ind],dp) , recc(prices,ind+1,INT_MAX,dp));
        }

        return dp[ind] = sell;


    }
    int maxProfit(vector<int>& prices) {
        vector<int> dp(prices.size() , -1);
        return recc(prices,0,INT_MAX,dp);
    }
};