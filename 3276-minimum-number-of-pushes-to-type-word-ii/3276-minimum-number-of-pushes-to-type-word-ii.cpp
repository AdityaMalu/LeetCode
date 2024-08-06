bool comp(const pair<int,int> &a ,const pair<int,int> &b)
    {
        return a.second > b.second;
    }

class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int> mp;
        vector<pair<char,int>> v;

        for(auto i : word){
            mp[i]++;
        }

        for (auto i : mp){
            v.push_back({i.first,i.second});
        }

        sort(v.begin(),v.end(),comp);


        int count = 1,ans = 0;
        for(auto i : v){
            char cur = i.first;
            int cnt = i.second;
            if(cur == '1' || cur == '*' || cur == '#' || cur == '0'){
                ans+=1;
            }
            else if (count <= 8){
                ans+= cnt;
            }
            else if( count <= 16){
                ans += cnt*2;
            }
            else if(count <= 24){
                ans += cnt*3;
            }
            else{
                ans += cnt*4;
            }
            count++;
        }

        return ans;
    }
};