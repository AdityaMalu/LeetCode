class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = 0, ans = 0;
        int maxi;
        maxi = *max_element(nums.begin(),nums.end());
        if(maxi<=0){
            return maxi;
        }
        for(int i = 0 ; i < nums.size() ; i++){
            max_sum += nums[i];
            ans = max(max_sum,ans);
            if(max_sum <0){
                max_sum = 0;
            }
        }
        return ans;
    }
};