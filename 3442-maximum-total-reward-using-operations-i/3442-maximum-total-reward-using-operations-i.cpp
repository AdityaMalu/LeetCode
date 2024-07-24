class Solution {
public:
    int dp[2001][4001];
    int recc(vector<int> & arr , int ind,int total){
        if(ind == arr.size()){
            return 0;
        }

        if(dp[ind][total] != -1) return dp[ind][total];
        int not_take = recc(arr,ind+1,total);
        int take;
        if(total < arr[ind]){
            take = arr[ind] + recc(arr,ind+1,total+arr[ind]);
        }

        return dp[ind][total] = max(not_take,take);
    }

    int maxTotalReward(vector<int>& r) {
        memset(dp,-1,sizeof(dp));
        sort(r.begin(),r.end());
        return recc(r,0,0);
    }
};