class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int maxi = nums.size();
        vector<int> vis(maxi+1,0),ans;


        for(auto i : nums){
            vis[i]++;
        }

        for(int i = 1 ; i <= maxi ; i++){
            if(vis[i] == 0){
                ans.push_back(i);
            }
        }

        return ans;
    }
};