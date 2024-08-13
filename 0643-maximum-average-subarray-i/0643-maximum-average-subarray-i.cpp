class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double temp = 0;

        for (int i = 0; i < k; i++) {
            temp += nums[i];
        }

        double ans = temp;

        for (int i = k; i < nums.size(); i++) {
            temp += nums[i] - nums[i - k];
            ans = max(ans, temp);
        }

        return ans / k;
    }
};
