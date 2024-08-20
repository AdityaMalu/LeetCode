class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int st = 0,e = 0;
        unordered_map<char,int> mp;
        while(e < s.size()){
            mp[s[e++]]++;
            ans = max(ans,e-st);
            while(st < e && mp[s[e]] != 0){
                mp[s[st++]]--;
            }
        }

        return ans;
    }
};