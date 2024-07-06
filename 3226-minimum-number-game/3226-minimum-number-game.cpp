class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0,j=1;
        while(j<nums.size()){
            swap(nums[i],nums[j]);
            i+=2;
            j+=2;
        }
        return nums;
    }
};