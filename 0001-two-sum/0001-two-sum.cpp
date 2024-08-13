class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> v;
        for(int i = 0  ; i < nums.size() ; i++){
            v.push_back({nums[i],i});
        } 
        sort(v.begin(), v.end());
        int i = 0, j = v.size() - 1;
        while (j > i) {
            if (v[j].first + v[i].first == target)
                return {v[i].second, v[j].second};
            if (v[j].first + v[i].first > target) {
                j--;
            } else {
                i++;
            }
        }
        return {};
    }
};