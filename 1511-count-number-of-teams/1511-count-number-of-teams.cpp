class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        if (n < 3) return 0;

        vector<int> inc(n, 0);
        vector<int> dec(n, 0);
        
        int count = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (rating[i] > rating[j]) {
                    inc[i]++;
                    count += inc[j];
                } else if (rating[i] < rating[j]) {
                    dec[i]++;
                    count += dec[j]; 
                }
            }
        }

        return count;
    }
};
