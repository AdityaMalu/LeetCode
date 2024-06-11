class Solution {
public:
    int maxVowels(string s, int k) {
        int i = 0,j = k,ans = 0,temp = 0;
        for(int i = 0 ; i < j ; i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                temp += 1;
            }
            ans = max(ans,temp);
        }

        while(j < s.size()){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                temp -= 1;
            }
            if(s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u'){
                temp += 1;
            }
            i++;
            j++;
            ans = max(ans,temp);
        }
        return ans;
    }
};