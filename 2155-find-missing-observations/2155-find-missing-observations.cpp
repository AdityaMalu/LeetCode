class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int total = mean * (rolls.size() + n);
        int seen = accumulate(rolls.begin(), rolls.end(), 0);
        int rem = total - seen;
        vector<int> ans(n, rem / n);
        if (rem > n * 6 || rem < 0) {
            return {};
        }
        if (rem / n == 0) {
            return {};
        }
        int to_add = rem % n;
        for (int i = 0; i < to_add; i++) {
            ans[i]++;
        }

        return ans;
    }
};