class Solution {
public:

    int recc(int i , int j , vector<int> &nums , vector<vector<int>> &dp){
        if (i == j) return 0;
        int maxi = INT_MIN;
        if(dp[i][j] != -1) return dp[i][j];
        for(int k = i ; k < j ; k++){
            maxi = max(maxi,(nums[i-1]*nums[k]*nums[j] + recc(i,k,nums,dp) + recc(k+1,j,nums,dp)));
        }

        return dp[i][j] =  maxi;

    }

    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size() , -1));

        for(int i = 0 ; i < nums.size() ; i++){
            dp[i][i] = 0;
        }

        for(int i = nums.size() - 1 ; i > 0 ; i--){
            for(int j = i + 1 ; j < nums.size() ; j++){
                int maxi = INT_MIN;
                for(int k = i ; k < j ; k++){
                    maxi = max(maxi,(nums[i-1]*nums[k]*nums[j] + dp[i][k] + dp[k+1][j]));
                }
                dp[i][j] = maxi;
            }
        }

        return dp[1][nums.size()-1];
        
        return recc(1,nums.size()-1,nums,dp);
    }
};