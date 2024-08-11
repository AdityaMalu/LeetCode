class Solution
{
public:
    void dfs(vector<vector<int>> &grid, vector<vector<int>> &vis, int row, int col)
    {
        vis[row][col] = 1;
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        for (int i = 0; i < 4; i++)
        {
            int newX = row + dx[i];
            int newY = col + dy[i];
            if (newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[0].size() and !vis[newX][newY] && grid[newX][newY] == 1)
            {
                dfs(grid, vis, newX, newY);
            }
        }
    }

    int islands(vector<vector<int>> &grid)
    {
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), 0));
        int count = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (!vis[i][j] && grid[i][j] == 1)
                {
                    count++;
                    dfs(grid, vis, i, j);
                }
            }
        }
        return count;
    }

    int minDays(vector<vector<int>> &grid)
    {
        int ini = islands(grid);
        if (ini > 1 || ini == 0)
            return 0;

        int row = grid.size();
        int col = grid[0].size();

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j])
                {
                    grid[i][j] = 0;
                    int newcnt = islands(grid);
                    if (newcnt > 1 || newcnt == 0)
                        return 1;
                    grid[i][j] = 1;
                    
                }
            }
        }

        return 2;
    }
};