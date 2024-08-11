class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int total = accumulate(nums.begin(),nums.end(),0);
        int req = (nums.size())*(nums.size()+1)/2;
        return req-total;
    }
};