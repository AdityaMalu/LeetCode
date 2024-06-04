class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        for(auto i : s){
            mp[i]++;
        }

        int ans = 0,temp=0;

        for(auto i  = mp.begin() ; i != mp.end() ; i++){
            ans+=i->second;
            if(i->second % 2 == 1){
                temp+=1;
            }
        }
        if (temp == 0)
        return ans-temp;
        return ans-temp+1;
    }
};