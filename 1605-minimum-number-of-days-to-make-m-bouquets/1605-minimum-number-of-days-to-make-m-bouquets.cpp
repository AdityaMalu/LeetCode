class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if (static_cast<long long>(m) * k > bloomDay.size()) return -1;

        auto canMakeBouquets = [&](int days) {
            int bouquets = 0;
            int flowers = 0;

            for (int bloom : bloomDay) {
                if (bloom <= days) {
                    flowers++;
                    if (flowers == k) {
                        bouquets++;
                        flowers = 0;
                    }
                } else {
                    flowers = 0;
                }
            }

            return bouquets >= m;
        };

        int left = *min_element(bloomDay.begin(), bloomDay.end());
        int right = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canMakeBouquets(mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
};
