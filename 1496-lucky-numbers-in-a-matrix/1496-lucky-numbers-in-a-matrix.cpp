class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> rowMin(rows, INT_MAX);
        vector<int> colMax(cols, INT_MIN);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                rowMin[i] = min(rowMin[i], matrix[i][j]);
            }
        }

        for (int j = 0; j < cols; j++) {
            for (int i = 0; i < rows; i++) {
                colMax[j] = max(colMax[j], matrix[i][j]);
            }
        }

        vector<int> ans;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == rowMin[i] && matrix[i][j] == colMax[j]) {
                    ans.push_back(matrix[i][j]);
                }
            }
        }

        return ans;
    }
};
