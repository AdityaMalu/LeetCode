class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int start = 0,ans = 0,count = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == 0){
                count++;
            }
            while(count > 1){
                if(nums[start] == 0){
                    count--;
                }
                start++;
            }
            ans = max(ans,i-start);
        }
        return ans;
    }
};