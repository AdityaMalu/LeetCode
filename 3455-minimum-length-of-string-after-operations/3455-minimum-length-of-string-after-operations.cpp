class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int> mp;
        int ans = 0;
        for(auto i : s){
            mp[i]++;
        }

        for(auto i: mp){
            if(i.second > 2){
                if(i.second%2 == 0) ans+=2;
                else ans +=1;
            }
            else{
                ans+=i.second;
            }
        }

        return ans;
    }
};