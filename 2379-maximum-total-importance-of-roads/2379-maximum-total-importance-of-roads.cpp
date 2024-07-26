class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        unordered_map<long long, long long> mp;
        
        for(auto road : roads) {
            mp[road[0]]++;
            mp[road[1]]++;
        }
        
        vector<pair<long long, long long>> vec(mp.begin(), mp.end());
        
        sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {
            return a.second > b.second;
        });
        
        for(long long i = 0; i < vec.size(); i++) {
            mp[vec[i].first] = n - i;
        }
        
        long long ans = 0;
        for(auto road : roads) {
            ans += mp[road[0]] + mp[road[1]];
        }
        
        return ans;
    }
};
