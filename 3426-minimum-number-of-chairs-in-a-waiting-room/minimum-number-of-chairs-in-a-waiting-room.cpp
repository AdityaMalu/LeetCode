class Solution {
public:
    int minimumChairs(string s) {
        int ans=0,temp = 0;
        for(auto i : s){
            if(i=='E'){
                temp+=1;
            }
            else{
                temp-=1;
            }
            ans = max(temp,ans);
        }
        return ans;
    }
};