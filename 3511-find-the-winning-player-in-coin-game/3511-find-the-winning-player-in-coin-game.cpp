class Solution {
public:
    string losingPlayer(int x, int y) {
        if (min(x,y/4)%2==0){
            return "Bob";
        }
        else{
            return "Alice";
        }
    }
};