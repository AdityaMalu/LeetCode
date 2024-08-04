class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int MOD = 1e9+7;
        vector<int> sums;
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            int temp = 0;
            for(int j = i; j < n ; j++){
                temp += nums[j];
                sums.push_back(temp);
            }
        }

        sort(sums.begin(), sums.end());

        for(int i = left-1 ; i <=right-1 ; i++){
            ans += sums[i];
            ans%=MOD;
        }

        return ans%MOD;
    }
};