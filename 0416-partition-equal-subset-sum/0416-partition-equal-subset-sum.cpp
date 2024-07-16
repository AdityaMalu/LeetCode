class Solution {
private:
    bool c(vector<int>& arr, int i, int sum, vector<vector<int>>& dp) {
        if (sum == 0) {
            return true;
        }
        if (i == arr.size() - 1) {
            if (sum == 0 || sum - arr[i] == 0) {
                return true;
            }
            return false;
        }
        if (sum < 0) return false;
        if (dp[i][sum] != -1) {
            return dp[i][sum] == 1;
        }

        bool b = c(arr, i + 1, sum - arr[i], dp) || c(arr, i + 1, sum, dp);
        dp[i][sum] = b ? 1 : 0;
        return b;
    }
public:
    bool canPartition(vector<int>& nums) {
        int totsum = 0;
        for (int num : nums) totsum += num;
        if (totsum % 2 == 1) return false;
        
        vector<vector<int>> dp(nums.size(), vector<int>(totsum / 2 + 1, -1));
        return c(nums, 0, totsum / 2, dp);
    }
};
