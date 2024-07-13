class Solution {
public:
    string rle(string s) {
        char prev = s[0];
        string ans;
        int count = 1;
        for(int i = 1; i < s.length(); i++) {
            if(prev == s[i]) {
                count++;
            } else {
                ans += count + '0';
                ans += prev;
                count = 1; 
            }
            prev = s[i];
        }
        ans += count + '0';
        ans += prev;
        return ans;
    }
    
    string countAndSay(int n) {
        string ans = "1";
        for(int i = 1; i < n; i++) {
            ans = rle(ans);
        }
        return ans;
    }
};