class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()<t.length()){
            swap(s,t);
        }
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;

        for(auto i : s){
            mp1[i]++;
        }
        for(auto i : t){
            mp2[i]++;
        }

        for(auto i : s){
            if(mp1[i] != mp2[i]){
                return false;
            }
        }
        return true;

    }
};