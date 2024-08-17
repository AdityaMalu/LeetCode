class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int row = points.size();
        int col = points[0].size();
        
        vector<long long> prev(col, 0);
        
        for (int j = 0; j < col; ++j) {
            prev[j] = points[0][j];
        }
        
        for (int i = 1; i < row; ++i) {
            vector<long long> left(col, 0), right(col, 0), curr(col, 0);
            
            left[0] = prev[0];
            for (int j = 1; j < col; ++j) {
                left[j] = max(left[j-1] - 1, prev[j]);
            }
            
            right[col-1] = prev[col-1];
            for (int j = col-2; j >= 0; --j) {
                right[j] = max(right[j+1] - 1, prev[j]);
            }
            
            for (int j = 0; j < col; ++j) {
                curr[j] = points[i][j] + max(left[j], right[j]);
            }
            
            prev = curr;
        }
        
        return *max_element(prev.begin(), prev.end());
    }
};
