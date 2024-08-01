class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int r_start = 0, r_end = matrix.size()-1, c_start = 0, c_end = matrix[0].size()-1;
        vector<int> ans;
        if(matrix.size() == 0) return ans;
        while(r_start <= r_end && c_start <= c_end){
            for(int i =  c_start ; i <= c_end ; i++){
                ans.push_back(matrix[r_start][i]);
            }

            r_start++;

            for(int i = r_start ; i <= r_end ; i++){
                ans.push_back(matrix[i][c_end]);
            } 

            c_end--;

            if(r_start <= r_end){
                for(int i = c_end ; i >= c_start ; i--){
                    ans.push_back(matrix[r_end][i]);
                }
            }
            
            r_end--;

            if(c_start <= c_end){
                for(int i = r_end ; i >= r_start ; i--){
                    ans.push_back(matrix[i][c_start]);
                }
            }

            c_start++;
        }

        return ans;
    }
};