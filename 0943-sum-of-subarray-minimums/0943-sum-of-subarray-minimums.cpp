class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
         const int MOD = 1e9 + 7;
        int n = arr.size();

        vector<int> PLE(n, -1), NLE(n, n);
        
        stack<int> stk;
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && arr[stk.top()] > arr[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                PLE[i] = stk.top();
            }
            stk.push(i);
        }

        while (!stk.empty()) stk.pop();

        for (int i = n - 1; i >= 0; --i) {
            while (!stk.empty() && arr[stk.top()] >= arr[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                NLE[i] = stk.top();
            }
            stk.push(i);
        }

        long long result = 0;
        for (int i = 0; i < n; ++i) {
            int left_count = i - PLE[i];
            int right_count = NLE[i] - i;
            result = (result + (long long)arr[i] * left_count * right_count) % MOD;
        }

        return result;
    }
};