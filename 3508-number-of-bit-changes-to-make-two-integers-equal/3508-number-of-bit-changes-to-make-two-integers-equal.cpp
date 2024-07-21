class Solution {
public:
    int minChanges(int n, int k) {
        int cnt = 0;
        for(int i = 0 ; i < 32 ; i++){
            if((n & 1) == 0 && (k & 1) == 1){
                return -1; 
            }
            if((n & 1) == 1 && (k & 1) == 0){
                cnt++;
            }
            n >>= 1;
            k >>= 1;
        }
        return cnt;
    }
};
