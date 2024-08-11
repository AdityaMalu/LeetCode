class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int i = 0, j = 0;

        for(auto c : commands){
            if(c == "LEFT" && j > 0){
                j--;
            }
            if(c == "RIGHT" && j < n - 1){
                j++;
            }
            if(c == "UP" && i > 0){
                i--;
            }
            if(c == "DOWN" && i < n - 1){
                i++;
            }
        }

        return (i * n) + j;
    }
};
