class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int total = 0; 
        for(int num : nums) {
            if(num == 1) {
                total++;
            }
        }

        if(total == 0 || total == n) {
            return 0;
        }

        nums.insert(nums.end(), nums.begin(), nums.end());

        int maxi = 0, count = 0;
        for(int i = 0; i < 2 * n; i++) {
            if(nums[i] == 1) {
                count++;
            }
            if(i >= total && nums[i - total] == 1) {
                count--;
            }
            maxi = max(maxi, count);
        }

        return total - maxi;
    }
};
