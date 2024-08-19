class Solution {
public:
    int recc(int n, int curr, int clipboard,vector<vector<int>> &dp){
        if(curr == n){
            return 0;
        }

        if(curr > n){
            return INT_MAX;
        }

        if(dp[curr][clipboard] != -1) return dp[curr][clipboard];

        int paste = INT_MAX;
        if(clipboard > 0 && curr + clipboard <= n){
            int pasteResult = recc(n, curr + clipboard, clipboard,dp);
            if (pasteResult != INT_MAX) {
                paste = 1 + pasteResult;
            }
        }

        int copy = INT_MAX;
        if(curr != clipboard){
            int copyResult = recc(n, curr, curr,dp);
            if (copyResult != INT_MAX) {
                copy = 1 + copyResult;
            }
        }

        return dp[curr][clipboard] = min(copy, paste);
    }

    int minSteps(int n) {
        if (n == 1) return 0;
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1)); 
        return recc(n, 1, 0,dp);
    }
};
