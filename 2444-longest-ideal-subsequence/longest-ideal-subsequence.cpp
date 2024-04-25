class Solution {
public:
    int longestIdealString(string s, int k) {
       vector<int> l(128, 0);
        for (char c : s) {
            int i = c;
            auto start = max(0, i - k);
            auto end = min(127, i + k);
            l[i] = *max_element(l.begin() + start, l.begin() + end + 1) + 1;
        }
        return *max_element(l.begin(), l.end());
    }
};