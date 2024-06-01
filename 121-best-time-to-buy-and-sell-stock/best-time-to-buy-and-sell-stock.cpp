class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int min1  = INT_MAX;
       int ans = 0;
       for(int i = 0 ; i<prices.size() ; i++){
           if (min1>prices[i]){
            min1 = prices[i];
           }
            else if( prices[i] - min1>ans){
              ans = prices[i] - min1;
          }
       }

        return ans; 
    }
};