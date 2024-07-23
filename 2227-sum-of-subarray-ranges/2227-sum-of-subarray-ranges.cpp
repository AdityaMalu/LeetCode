class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        vector<int> NLE(n, n), PLE(n, -1), NGE(n, n), PGE(n, -1);
        vector<long long> SubSmall(n, 0), SubMax(n, 0);
        stack<int> stk;

        // Next Lesser Element (NLE)
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && nums[i] <= nums[stk.top()]) {
                stk.pop();
            }
            if (!stk.empty()) {
                NLE[i] = stk.top();
            }
            stk.push(i);
        }

        while (!stk.empty()) stk.pop();

        // Previous Lesser Element (PLE)
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && nums[i] < nums[stk.top()]) {
                stk.pop();
            }
            if (!stk.empty()) {
                PLE[i] = stk.top();
            }
            stk.push(i);
        }

        while (!stk.empty()) stk.pop();

        // Next Greater Element (NGE)
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && nums[i] >= nums[stk.top()]) {
                stk.pop();
            }
            if (!stk.empty()) {
                NGE[i] = stk.top();
            }
            stk.push(i);
        }

        while (!stk.empty()) stk.pop();

        // Previous Greater Element (PGE)
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && nums[i] > nums[stk.top()]) {
                stk.pop();
            }
            if (!stk.empty()) {
                PGE[i] = stk.top();
            }
            stk.push(i);
        }

        // Calculate the subarray ranges
        for (int i = 0; i < n; ++i) {
            long long left_count = i - PLE[i];
            long long right_count = NLE[i] - i;
            SubSmall[i] = static_cast<long long>(nums[i]) * left_count * right_count;

            left_count = i - PGE[i];
            right_count = NGE[i] - i;
            SubMax[i] = static_cast<long long>(nums[i]) * left_count * right_count;

            ans += (SubMax[i] - SubSmall[i]);
        }

        return ans;
    }
};
