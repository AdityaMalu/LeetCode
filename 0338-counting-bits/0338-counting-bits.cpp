class Solution {
public:
    vector<int> countBits(int n) {
        if(n==0){
            return {0};
        }
        if(n == 1){
            return {0,1};
        }
        if(n == 2){
            return {0,1,1};
        }
        vector<int> dp(n+1);
        int power = 2;
        dp[0] = 0;
        dp[1] = dp[2] = 1;
        long long powertwo = pow(2,power-1);
        double nxt =  pow(2,power);
        for(int i = 3 ; i<=n  ; i++){
            if(i == nxt){
                dp[i] = 1;
                powertwo = nxt;
                nxt = pow(2,++power);
            }
            else{
                dp[i] = dp[powertwo] + dp[i - powertwo];
            }
        }
        return dp;
    }
};