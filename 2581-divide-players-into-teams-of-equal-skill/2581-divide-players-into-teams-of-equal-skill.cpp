class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        long long sum = skill[0] + skill[skill.size()-1];
        long long i = 0, j = skill.size()-1;
        vector<pair<int,int>> temp;
        while(i < j){
            if(sum != skill[i] + skill[j]){
                return -1;
            }
            else{
                temp.push_back({skill[i],skill[j]});
            }
            i++;
            j--;
        }
        long long ans = 0;
        for(auto i : temp){
            int first = i.first;
            int second = i.second;
            ans += first*second;
        }
        return ans;
    }
};