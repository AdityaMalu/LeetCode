class Solution {
public:

    int recc(vector<int>& cuts, int i,int j,vector<vector<int>> &dp){
        if (i > j) return 0;
        
        if (dp[i][j] != -1) return dp[i][j];
        
        int mini = INT_MAX;
        
        for (int k = i; k <= j; k++) {
            int cost = cuts[j + 1] - cuts[i - 1] + recc(cuts, i, k - 1, dp) + recc(cuts, k + 1, j, dp);
            mini = min(mini, cost);
        }
        
        return dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int>(m, -1));
        return recc(cuts,1,m-2,dp);
    }
};