class Solution {
public:

    int recc(int i , int j , vector<int> &nums , vector<vector<int>> &dp){
        if (i == j) return 0;
        int maxi = INT_MIN;
        if(dp[i][j] != -1) return dp[i][j];
        for(int k = i ; k < j ; k++){
            maxi = max(maxi,(nums[i-1]*nums[k]*nums[j] + recc(i,k,nums,dp) + recc(k+1,j,nums,dp)));
        }

        return dp[i][j] =  maxi;

    }

    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size() , -1));
        return recc(1,nums.size()-1,nums,dp);
    }
};