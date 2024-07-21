class Solution {
public:

    bool recc(vector<int> &nums, int ind, int sum,int target,vector<vector<int>> &dp){
        
        if(sum >= target || ind >= nums.size()){
            if(sum == target) return true;
            return false;
        }

        if(dp[ind][sum] != -1){
            return dp[ind][sum] == 1;
        }
        bool not_pick = recc(nums,ind+1,sum,target,dp);
        bool pick = false;
        if(sum < target){
            pick = recc(nums,ind+1,sum+nums[ind],target,dp);
        }
        if(pick||not_pick) dp[ind][sum] = 1;
        else dp[ind][sum] = 0;
        return pick || not_pick;
    }

    bool canPartition(vector<int>& nums) {
        // int sum1 = accumulate(nums.begin() , nums.end() , 0);
        // vector<vector<int>> dp(nums.size(),vector<int>(sum1/2+1,-1));
        // if(sum1%2 == 1){
        //     return false;
        // }
        // else{
        //     return recc(nums,0,0,sum1/2,dp);
        // }

        int sum1 = accumulate(nums.begin(), nums.end(), 0);
        if (sum1 % 2 != 0) {
            return false;
        }
        int target = sum1 / 2;
        int n = nums.size();
        
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
        
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = true;
        }
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= target; ++j) {
                if (j >= nums[i - 1]) {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        
        return dp[n][target];
    }
};