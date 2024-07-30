//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    void recc(vector<vector<int>> &mat, int row, int col, vector<vector<int>> &vis, string temp, vector<string> &ans, int n) {
    if (row == n - 1 && col == n - 1) {
        ans.push_back(temp);
        return;
    }
    
    if (row < 0 || row >= mat.size() || col < 0 || col >= mat[0].size() || vis[row][col] || mat[row][col] == 0) {
        return;
    }
    
    vis[row][col] = 1;
    
    if (row < n - 1 && mat[row + 1][col] == 1 && vis[row + 1][col] == 0) {
        recc(mat, row + 1, col, vis, temp + 'D', ans, n);
    }
    
    if (col > 0 && mat[row][col - 1] == 1 && vis[row][col - 1] == 0) {
        recc(mat, row, col - 1, vis, temp + 'L', ans, n);
    }
    
    if (col < n - 1 && mat[row][col + 1] == 1 && vis[row][col + 1] == 0) {
        recc(mat, row, col + 1, vis, temp + 'R', ans, n);
    }
    
    if (row > 0 && mat[row - 1][col] == 1 && vis[row - 1][col] == 0) {
        recc(mat, row - 1, col, vis, temp + 'U', ans, n);
    }
    
    vis[row][col] = 0;
}

vector<string> findPath(vector<vector<int>> &mat) {
    int row = mat.size();
    if (row == 0 || mat[0][0] == 0 || mat[row - 1][row - 1] == 0) {
        return {};
    }
    
    int col = mat[0].size();
    vector<vector<int>> vis(row, vector<int>(col, 0));
    vector<string> ans;
    recc(mat, 0, 0, vis, "", ans, row);
    return ans;
}

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends