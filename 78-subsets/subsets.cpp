class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int m = 1<<n;

        vector<vector<int>> ans(m);

        for(int i = 0 ; i < m ; i ++){
            for(int j = 0 ; j < n ; j++){
                if(i & (1<<j)){
                    ans[i].push_back(nums[j]);
                }
            }
        }

        return ans;
    }
};