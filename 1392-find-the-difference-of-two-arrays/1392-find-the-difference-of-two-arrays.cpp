
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans;
        map<int, int> mp;
        map<int, int> mp2;

        for(auto i : nums2){
            mp2[i]=1;
        }
        for(auto i : nums1){
            mp[i]=1;
            mp2[i]=0;
        }
        for(auto i : nums2){
            mp[i]=0;
        }
        vector<int> v1;
        vector<int> v2;

        for(auto i : mp){
            if(i.second > 0) v1.push_back(i.first);
        }
        for(auto i : mp2){
            if(i.second > 0) v2.push_back(i.first);
        }

        ans.push_back(v1);
        ans.push_back(v2);

        return ans;
    }
};