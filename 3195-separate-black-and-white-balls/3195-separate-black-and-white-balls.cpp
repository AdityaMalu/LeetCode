class Solution {
public:
    long long minimumSteps(string s) {
        long long ans = 0;
        long long one_count = 0;
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == '1'){
                one_count +=1;
            }
            else{
                ans += one_count;
            }
        }
        return ans;
    }
};