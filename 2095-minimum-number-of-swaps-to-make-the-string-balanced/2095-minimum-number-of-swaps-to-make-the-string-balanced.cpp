class Solution {
public:
    int minSwaps(string s) {
        int si = 0;
        int n  = s.size();
        for(auto i : s){
            if( i  == '['){
                si++;
            }
            else if(si > 0){
                si--;
            }
        }
        return (si + 1)/2;

    }
};