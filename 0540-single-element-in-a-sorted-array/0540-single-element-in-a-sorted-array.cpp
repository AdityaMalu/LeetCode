class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n ==1){
            return nums[0];
        }
        if(nums[0] != nums[1]){
            return nums[0];
        }
        if(nums[n-2] != nums[n-1]){
            return nums[n-1];
        }
        int _min =1;
        int _max = n-2;
        while(_max>=_min){
            int mid = (_min + _max)/2;
            if(nums[mid] != nums[mid+1] && nums[mid] != nums[mid-1]){
                return nums[mid];
            }
            if((mid%2 ==1 && nums[mid-1] == nums[mid]) || (mid%2==0 && nums[mid] == nums[mid+1]))
            {
                _min = mid+1;
            }
            else{
                _max = mid -1;
            }
        }
        return -1; 
    }
};