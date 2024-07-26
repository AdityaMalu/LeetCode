class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        if (hour < n - 1) {
            return -1;
        }

        double dl = 0;
        double dr = 0;
        for (int d : dist) {
            double cur = static_cast<double>(d);
            dl += cur / hour;
            dr += cur / (hour - n + 1);
        }

        int l = floor(min(dl, 10e7));
        int r = ceil(min(dr, 10e7));
        
        auto check = [&](const vector<int>& dist, double hour, int speed) {
            double time = 0;
            for (int i = 0; i < dist.size() - 1; ++i) {
                time += ceil(static_cast<double>(dist[i]) / speed);
            }
            time += static_cast<double>(dist.back()) / speed;
            return time <= hour;
        };
        
        int ans = -1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (check(dist, hour, m)) {
                ans = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        
        return ans;
    }
};
