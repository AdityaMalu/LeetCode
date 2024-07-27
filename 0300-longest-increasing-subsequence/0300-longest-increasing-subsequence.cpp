class Solution
{
public:
    int recc(vector<int> &nums, int ind, int prev, vector<vector<int>> &dp)
    {
        if (ind == nums.size())
        {
            return 0;
        }

        if (dp[ind][prev + 1] != INT_MIN)
            return dp[ind][prev + 1];

        int pick = 0, npick;
        npick = recc(nums, ind + 1, prev, dp);
        if (prev == -1 || nums[ind] > nums[prev])
        {
            pick = 1 + recc(nums, ind + 1, ind, dp);
        }

        return dp[ind][prev + 1] = max(pick, npick);
    }

    int lengthOfLIS(vector<int> &nums)
    {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size() + 1, INT_MIN));
        return recc(nums, 0, -1, dp);
    }
};
