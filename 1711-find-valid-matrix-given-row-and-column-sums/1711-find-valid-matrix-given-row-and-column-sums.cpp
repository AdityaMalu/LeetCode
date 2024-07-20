#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int numRows = rowSum.size();
        int numCols = colSum.size();
        vector<vector<int>> ans(numRows, vector<int>(numCols, 0));

        for (int r = 0; r < numRows; ++r) {
            for (int c = 0; c < numCols; ++c) {
                ans[r][c] = min(rowSum[r], colSum[c]);
                rowSum[r] -= ans[r][c];
                colSum[c] -= ans[r][c];
            }
        }

        return ans;
    }
};
