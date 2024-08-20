class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.size() < t.size()) {
            return "";
        }
        vector<int> mp(128, 0);

        int cnt = t.size();
        int st = 0, e = 0, minlen = INT_MAX, si = 0;

        for (char c : t) {
            mp[c]++;
        }

        while (e < s.size()) {
            if (mp[s[e++]]-- > 0) {
                cnt--;
            }

            while (cnt == 0) {

                if (e - st < minlen) {
                    si = st;
                    minlen = e - st;
                }

                if (mp[s[st++]]++ == 0) {
                    cnt++;
                }
            }
        }

        return minlen == INT_MAX ? "" : s.substr(si, minlen);
    }
};