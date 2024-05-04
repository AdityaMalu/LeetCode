class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin() , people.end());
        int one= 0, two = people.size() - 1, ans = 0;
        while(one <= two){
            if(people[one] + people[two] <= limit ){
                one++;
            }
            two--;
            ans++;
        }
        return ans;
    }
};