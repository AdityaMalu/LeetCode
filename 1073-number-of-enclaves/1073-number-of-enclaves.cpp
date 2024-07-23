class Solution {
public:

    
    void dfs(vector<vector<int>> &grid, int row, int col , vector<vector<int>> &vis){
        vis[row][col] = 1;
        int delrow[] = {0,0,-1,1};
        int delcol[] = {1,-1,0,0};
        for(int i = 0 ; i< 4 ; i++){
            int newR  = row + delrow[i];
            int newC = col + delcol[i];
            if(newR >= 0 && newR < grid.size() && newC >= 0 && newC < grid[0].size() && vis[newR][newC] != 1 && grid[newR][newC] == 1){
                grid[newR][newC] = 0;
                dfs(grid,newR,newC,vis);
            }
        }
        
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int rSize = grid.size();
        int cSize = grid[0].size();
        vector<vector<int>> vis(rSize,vector<int>(cSize , 0));
        int ans = 0;
        for(int i = 0 ; i < rSize ; i++){
            if(grid[i][0] == 1){
                dfs(grid,i,0,vis);
            }
            if(grid[i][cSize - 1] == 1){
                dfs(grid,i,cSize - 1,vis);
            }
        }

        for(int i = 0 ; i < cSize ; i++){
            if(grid[0][i] == 1){
                dfs(grid,0,i,vis);
            }
            if(grid[rSize-1][i] == 1){
                dfs(grid,rSize-1,i,vis);
            }
        }

        for(int i = 0 ; i < rSize ; i++){
            for(int j = 0 ;j<cSize ; j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    ans++;
                }
            }
        }

        return ans;

    }
};