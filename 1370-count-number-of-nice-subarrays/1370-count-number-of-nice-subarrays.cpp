class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
       for(int i = 0 ; i < nums.size() ; i++){
        if(nums[i]%2 == 1){
            nums[i] = 1;
        }
        else{
            nums[i]  = 0;
        }
       }

       unordered_map<int,int>mp;
       mp[0] = 1;
       int curr_sum = 0;
       int count = 0;
       for(auto i: nums){
            curr_sum += i;
            if(mp.find(curr_sum-k) != mp.end()){
                count += mp[curr_sum-k];
            }
            mp[curr_sum]++;
       }

       return count; 
    }
};