

class Solution {
public:
    int recc(vector<int>& nums, int ind, int target,unordered_map<int, unordered_map<int, int>>& dp) {
        if (ind == nums.size()) {
            return target == 0 ? 1 : 0;
        }

        if (dp[ind].count(target)) return dp[ind][target];

        int plus = recc(nums, ind + 1, target - nums[ind], dp);
        int minus = recc(nums, ind + 1, target + nums[ind], dp);

        dp[ind][target] = plus + minus;
        return dp[ind][target];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int,unordered_map<int, int>> dp;
        return recc(nums, 0, target, dp);
    }
};
