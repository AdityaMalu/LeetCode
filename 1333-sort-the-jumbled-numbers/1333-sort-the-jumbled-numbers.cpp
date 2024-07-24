#include <vector>
#include <algorithm>

class Solution {
public:
    vector<int> sortJumbled(std::vector<int>& mapping, std::vector<int>& nums) {
        vector<pair<int, int>> mapped_nums;

        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            int mapped = 0;
            int place = 1;

            if (num == 0) {
                mapped = mapping[0];
            } else {
                while (num > 0) {
                    int digit = num % 10;
                    mapped += mapping[digit] * place;
                    place *= 10;
                    num /= 10;
                }
            }

            mapped_nums.push_back({mapped, i});
        }

        stable_sort(mapped_nums.begin(), mapped_nums.end());

        vector<int> ans(nums.size());
        for (int i = 0; i < mapped_nums.size(); ++i) {
            ans[i] = nums[mapped_nums[i].second];
        }

        return ans;
    }
};
