class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostKDistinct(nums, k) - atMostKDistinct(nums, k - 1);
    }

private:
    int atMostKDistinct(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        int start = 0, end = 0, distinct_count = 0, result = 0;
        
        while (end < nums.size()) {
            if (count[nums[end]] == 0) {
                distinct_count++;
            }
            count[nums[end]]++;
            end++;

            while (distinct_count > k) {
                count[nums[start]]--;
                if (count[nums[start]] == 0) {
                    distinct_count--;
                }
                start++;
            }

            result += end - start;
        }

        return result;
    }
};
