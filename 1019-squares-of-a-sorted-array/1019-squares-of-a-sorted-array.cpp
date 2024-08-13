class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        int i = 0,j = nums.size() - 1,k = nums.size() - 1;
        while (k >= 0) {
            if (abs(nums[i]) > abs(nums[j])) {
                ans[k] = pow(nums[i], 2);
                i++;
            } else {
                ans[k] = pow(nums[j], 2);
                j--;
            }
            k--;
        }

        return ans;
    }
};