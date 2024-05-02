class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int first = 0;
        int last = nums.size()-1;
        while(first < last){
            if(-(nums[first]) == nums[last]){
                return nums[last];
            }
            else if(-(nums[first]) < nums[last]){
                last--;
            }
            else{
                first++;
            }
        }
        return -1;
    }
};