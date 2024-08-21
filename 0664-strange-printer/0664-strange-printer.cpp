class Solution {
public:
    int recc(int i, int j, string& s, vector<vector<int>>& dp) {
        if (i > j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        char let = s[i];

        int ans = 1 + recc(i + 1, j, s,dp);
        for (int k = i + 1; k <= j; k++) {
            if (s[k] == let) {
                int maybe = recc(i, k - 1, s, dp) + recc(k + 1, j, s, dp);
                ans = min(ans, maybe);
            }
        }

        return dp[i][j] = ans;
    }

    int strangePrinter(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
        return recc(0, s.size() - 1, s, dp);
    }
};