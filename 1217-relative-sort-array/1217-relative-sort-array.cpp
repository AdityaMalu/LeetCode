class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> mp;
        vector<int> ans;
        int ind = 0;
        for(auto i : arr1){
            mp[i]++;
        }
        for(auto i : arr2){
            for(int j = 0 ; j < mp[i] ; j++){
                ans.push_back(i);
                ind++;
            }
            mp[i] = 0;
        }

        for(auto i : mp){
            if(i.second){
                while(i.second){
                    ans.push_back(i.first);
                    i.second--;
                }
            }
        }

        sort(ans.begin()+ind,ans.end());

        return ans;



    }
};