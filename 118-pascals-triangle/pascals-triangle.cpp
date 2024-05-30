class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        int temp = 1;
       
        for(int i = 1 ; i < numRows+1 ; i++ ){
             vector<int> temp1(1,1);
            for( int j = 1 ; j < i ; j++ ){
                temp = (i-j)*temp;
                temp/=j;
                temp1.push_back(temp);
            }
            ans.push_back(temp1);
        }
        return ans;
    }
};