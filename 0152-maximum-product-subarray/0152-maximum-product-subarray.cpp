class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int size = nums.size();
        double ans = INT_MIN;
        double pre = 1,suff=1;
        for(int i = 0 ; i < size ; i++){
            pre*= nums[i];
            suff*= nums[size-1-i];
            ans = max({ans,pre,suff});
            if(pre == 0) pre =1;
            if(suff == 0) suff = 1;
        }
        return ans;
    }
};