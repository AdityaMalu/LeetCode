class Solution {
public:
    int scoreOfString(string s) {
        int one = 0,two = 1,ans = 0;
        while(two<=s.size()-1){
            ans+=abs((s[one] - s[two]));
            one++;
            two++;
        }
        return ans;
    }
};