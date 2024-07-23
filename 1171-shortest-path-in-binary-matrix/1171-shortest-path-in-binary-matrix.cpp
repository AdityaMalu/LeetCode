class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid){
        int rSize = grid.size();
        int cSize = grid[0].size();
        vector<vector<int>> vis(rSize,vector<int>(cSize,0));


        queue<pair<pair<int,int>,int>> q;
        if(grid[0][0] == 0 && grid[rSize-1][cSize -1] == 0)
        {
            q.push({{0,0},1});
            vis[0][0] = 1;
        }

        int ans = INT_MAX;

        while(!q.empty()){
            auto curr = q.front();
            int currRow = curr.first.first;
            int currCol = curr.first.second;
            int dist = curr.second;
            q.pop();
    
            if(currRow == rSize -1 && currCol == cSize -1){
                ans =  min(dist,ans);
            }
            int travRow[] = {0,0,1,-1,1,-1,1,-1};
            int travCol[] = {1,-1,0,0,-1,1,1,-1};

            for(int i = 0 ; i < 8 ; i++){
                int drow = currRow + travRow[i];
                int dcol = currCol + travCol[i];

                if(drow >= 0 && drow < rSize && dcol >= 0 && dcol < cSize && vis[drow][dcol] != 1 && grid[drow][dcol] == 0){
                    q.push({{drow,dcol},dist+1});
                    vis[drow][dcol] = 1;
                }
            }
        }

        if(ans == INT_MAX) return -1;
        else return ans;
    }
};