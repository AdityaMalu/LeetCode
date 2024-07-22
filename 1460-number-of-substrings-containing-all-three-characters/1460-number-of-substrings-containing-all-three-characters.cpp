class Solution {
public:
    int numberOfSubstrings(string s) {
        int last[] = {-1,-1,-1}, cnt = 0;
        for(int i = 0 ; i < s.size() ; i++){
            last[s[i]-'a']=i;
            cnt += 1 + min(last[0],min(last[1],last[2]));
        }
        return cnt;
    }
};