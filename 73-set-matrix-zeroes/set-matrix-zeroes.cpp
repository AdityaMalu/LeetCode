class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rowlen = matrix.size();
        int collen = matrix[0].size();

        int col0 = 1;

        for( int i = 0 ; i < rowlen ; i++){
            for ( int j = 0 ; j < collen ; j++){
                if (matrix[i][j] == 0){
                    matrix[i][0] = 0;

                    if(j != 0){
                        matrix[0][j] = 0;
                    }
                    else{
                        col0 = 0;
                    }
                }
            }
        }

        for( int i = 1 ; i < rowlen ; i++){
            for(int j =1; j< collen ; j++){
                
                if (matrix[i][j] != 0){
                    if (matrix[0][j] == 0 || matrix[i][0] == 0){
                        matrix[i][j] = 0;
                    }
                }
            }
        }

        if (matrix[0][0] == 0){
            for(int i = 0 ; i < collen ; i++){
                matrix[0][i] = 0;
            }
        }

        if(col0 == 0){
            for(int i = 0 ; i < rowlen ; i++){
                matrix[i][0] = 0;
            }
        }
        return;
        
    }
};