//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:


    bool dfs(vector<vector<int>>& grid, int row, int col, vector<vector<bool>>& visited) {
        // Check bounds and if the cell is already visited or is a wall
        if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || visited[row][col] || grid[row][col] == 0) {
            return false;
        }
    
        // If the current cell is the destination
        if (grid[row][col] == 2) {
            return true;
        }
    
        // Mark the cell as visited
        visited[row][col] = true;
    
        // Possible moves: left, right, up, down
        int drow[] = {0, 0, -1, 1};
        int dcol[] = {-1, 1, 0, 0};
    
        // Explore all possible directions
        for (int i = 0; i < 4; i++) {
            int curr_row = row + drow[i];
            int curr_col = col + dcol[i];
            if (dfs(grid, curr_row, curr_col, visited)) {
                return true;
            }
        }
    
        return false;
    }

    bool is_Possible(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
    
        // Find the starting cell with the value 1 (source)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    return dfs(grid, i, j, visited);
                }
            }
        }
    
        return false;
    }

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}
// } Driver Code Ends