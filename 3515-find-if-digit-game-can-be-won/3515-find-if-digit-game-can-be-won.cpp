class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int sum = 0;
        for(auto i : nums){
            if(i>=10){
                sum+=i;
            }
        }

        int total = accumulate(nums.begin(),nums.end(),0);

        if(sum == total-sum) return false;
        return true;
    }
};