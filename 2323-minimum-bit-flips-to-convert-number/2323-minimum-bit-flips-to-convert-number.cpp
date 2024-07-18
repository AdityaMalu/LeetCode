class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xori = start^goal,ans=0;
        while(xori>0){
            if(xori & 1){
                ans++;
            }
            xori = xori>>1;
        }
        return ans;

    }
};