class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0, j = 0, temp = 0, ans = INT_MAX;
        while (j < nums.size()) {
            temp += nums[j];
            while (temp >= target) {
                ans = min(ans, j - i + 1);
                temp -= nums[i];
                i++;
            }
            j++;
        }

        return ans == INT_MAX ? 0 : ans;
    }
};