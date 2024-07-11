class Solution {
public:
    void rec(vector<int> &nums, int ind, vector<vector<int>> &ans, vector<int> &temp){
        ans.push_back(temp);
        for(int i = ind;i<nums.size(); i++){
            if(i != ind && nums[i]==nums[i-1]){
                continue;
            }
            temp.push_back(nums[i]);
            rec(nums,i+1,ans,temp);
            temp.pop_back();
        }
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        rec(nums,0,ans,temp);
        return ans;
    }
};