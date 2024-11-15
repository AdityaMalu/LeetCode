class Solution {
public:
    bool isPos(int n, vector<int> &arr , int mid){
        int stores = 0;
        for(int x : arr){
            stores+= x/mid;
            if(x%mid) stores++;
            if (stores > n) return 0;
        }
        return stores<=n;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int s = 1 ,e = 1e5, ans = 1;
        while(s <= e){
            int mid = (s+e)/2;
            if(isPos(n,quantities,mid)){
                ans = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return ans;
    }
};