class Solution {
public:
    int maxProduct(vector<int>& nums) {
        double l = 1;
        double r = 1,ans = INT_MIN;
        for(int i = 0 ; i < nums.size() ; i++){
            l = l*nums[i];
            r = r*nums[nums.size()-i-1];
            ans = max(l,ans);
            ans = max(r,ans);
            if (l == 0) l = 1;
            if (r == 0) r = 1;
        }
        return ans;
    }
};