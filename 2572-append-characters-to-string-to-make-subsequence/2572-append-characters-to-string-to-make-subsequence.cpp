class Solution {
public:
    int appendCharacters(string s, string t) {
        int s_size = s.size(),t_size = t.size(),ind = 0;
        for (int i = 0 ; i < s.size() ; i++){
            if(s[i] == t[ind]){
                ind++;
            }
        }
        return (t.size() - ind);

    }
};