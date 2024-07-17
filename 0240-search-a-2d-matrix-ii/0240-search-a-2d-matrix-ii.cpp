class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(),col = matrix[0].size();
        int i = row-1, j = 0;
        while(j < col && i >= 0){
            if(matrix[i][j] == target){
                return true;
            }
            if(matrix[i][j] > target){
                i--;;
            }
            else{
                j++;
            }
        }
        return false;
    }
};