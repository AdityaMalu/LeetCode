class Solution {
public:
    int recurr(int ind,int prev_ind,vector<vector<int>> &dp, vector<int> &nums){
        if(ind == nums.size()){
            return 0;
        }

        if(dp[ind][prev_ind + 1] != -1){
            return dp[ind][prev_ind+1];
        }

        int take = 0;

        int not_take = recurr(ind+1,prev_ind,dp,nums);

        if(prev_ind == -1 || nums[ind] > nums[prev_ind]){
            take = 1 + recurr(ind+1,ind,dp,nums);
        }

        return dp[ind][prev_ind +1] = max(not_take,take);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size()+1,-1));
        return recurr(0,-1,dp,nums);
        
    }
};