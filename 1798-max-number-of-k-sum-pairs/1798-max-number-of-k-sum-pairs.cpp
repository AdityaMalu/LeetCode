class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
     int start = 0,end = nums.size()-1,ans = 0;
     sort(nums.begin() , nums.end());
     while(end > start){
            if(nums[start] + nums[end] == k){
                ans++;
                start++;
                end--;
            }
            else if(nums[start] + nums[end] > k){
                end--;
            }
            else{
                start++;
            }
        }
    return ans;    
    }
};