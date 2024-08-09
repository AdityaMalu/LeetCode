class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int ans = 0;

        if (row < 3 || col < 3) return 0;

        auto isMagic = [&](int r, int c) {
            vector<int> vals;
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    vals.push_back(grid[r + i][c + j]);
                }
            }

            sort(vals.begin(), vals.end());
            
            for (int i = 0; i < 9; ++i) {
                if (vals[i] != i + 1) return false;
            }
            
            int sum = grid[r][c] + grid[r][c+1] + grid[r][c+2];
            return (grid[r+1][c] + grid[r+1][c+1] + grid[r+1][c+2] == sum &&
                    grid[r+2][c] + grid[r+2][c+1] + grid[r+2][c+2] == sum &&
                    grid[r][c] + grid[r+1][c] + grid[r+2][c] == sum &&
                    grid[r][c+1] + grid[r+1][c+1] + grid[r+2][c+1] == sum &&
                    grid[r][c+2] + grid[r+1][c+2] + grid[r+2][c+2] == sum &&
                    grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2] == sum &&
                    grid[r][c+2] + grid[r+1][c+1] + grid[r+2][c] == sum);
        };

        for (int r = 0; r <= row - 3; ++r) {
            for (int c = 0; c <= col - 3; ++c) {
                if (isMagic(r, c)) ++ans;
            }
        }

        return ans;
    }
};
