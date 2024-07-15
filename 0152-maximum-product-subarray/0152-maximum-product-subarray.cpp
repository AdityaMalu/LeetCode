class Solution {
public:
    int maxProduct(vector<int>& nums) {
        double n = nums.size(), pre = 1, suc = 1,ans = INT_MIN;
        for(int i = 0 ; i < n ; i++){

            if(pre == 0) pre = 1;
            if(suc == 0) suc = 1;
            pre *= nums[i];
            suc *= nums[n-i-1];
            ans = max(ans,max(pre,suc));
        }

        return ans;
    }
};