class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size(),ans =INT_MAX;
        vector<int> pre_a(n+1,0);
        vector<int> suf_b(n+1,0);
        for(int i = 1 ; i < n+1 ; i++){
            if(s[i-1] == 'b'){
                suf_b[i] = suf_b[i-1]+1;
            }
            else{
                suf_b[i] = suf_b[i-1];
            }
        }

        for(int i = n; i>=1; i--){
            if(s[i-1] == 'a'){
                pre_a[i-1] = pre_a[i]+1;
            }
            else{
                pre_a[i-1] = pre_a[i];
            }
        }

        for (int i = 0; i <= n; ++i) {
            ans = min(ans, pre_a[i] + suf_b[i]);
        }
        return ans;
    }
};