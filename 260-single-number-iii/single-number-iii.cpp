class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int> hash;
        vector<int>ans;
        for(int i = 0 ;i < nums.size() ; i++){
            hash[nums[i]]++;
        }
        for (auto itr = hash.begin(); itr != hash.end(); itr++) {
        if (itr->second == 1) {
            ans.push_back(itr->first);
        }
    }
        return ans; 
    }
};