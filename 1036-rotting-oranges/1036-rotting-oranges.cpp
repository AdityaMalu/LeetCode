class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> vis = grid;
        int ans = 0;
        queue<pair<pair<int,int>,int>> q;

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                }
            }
        }

        int rtrav[] = {-1, 0, 1, 0};
        int ctrav[] = {0, 1, 0, -1};

        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            int row = curr.first.first;
            int col = curr.first.second;
            int time = curr.second;
            ans = max(ans, time);
            vis[row][col] = 2;

            for(int i = 0; i < 4; i++){
                int newRow = row + rtrav[i];
                int newCol = col + ctrav[i];

                if(newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && vis[newRow][newCol] == 1){
                    q.push({{newRow, newCol}, time + 1});
                    vis[newRow][newCol] = 2;
                }
            }
        }
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(vis[i][j] == 1){
                    return -1; 
                }
            }
        }

        return ans;
    }
};
