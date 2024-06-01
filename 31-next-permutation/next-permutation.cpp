class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ind1 = nums.size(),ind2 = nums.size()-2;
        while(ind2>=0 && nums[ind2] >= nums[ind2+1]){
                ind2--;
            }
        if(ind2 < 0){
            reverse(nums.begin(),nums.end());
            return;
        }
        ind1 = ind1-1;
        while(ind1>ind2 && nums[ind1]<=nums[ind2]){
            ind1--;
        }
        swap(nums[ind1],nums[ind2]);
        sort(nums.begin() + ind2 + 1, nums.end());
        return;
    }
};