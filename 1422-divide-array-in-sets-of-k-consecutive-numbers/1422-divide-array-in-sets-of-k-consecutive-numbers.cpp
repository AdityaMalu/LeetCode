class Solution {
public:
    bool isPossibleDivide(vector<int>& hand, int groupSize) {
        map<int,int> mp;
        int cnt  = 0;
        if(hand.size()%groupSize != 0){
            return 0;
        }
        for(int i : hand){
            mp[i]++;
        }

        for(auto i : mp){
            int num = i.first;
            if(i.second == 0) continue;
            for(int j = num ; j < num+groupSize ; j++){
                if (mp[j] == 0 || mp[j]<i.second){
                    return false;
                }
                mp[j]-=i.second;
            }  
        }
        return 1;
    }
};