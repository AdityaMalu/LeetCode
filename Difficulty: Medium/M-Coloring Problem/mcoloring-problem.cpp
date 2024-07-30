//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:

    bool isSafe(int &u, int &c, int n, bool graph[101][101],vector<int> &col){
        for(int i = 0 ; i < n ; i++){
            if(u != i && graph[u][i] && col[i] == c){
                return false;
            }
        }
        return true;
    }
    
    bool recc(int u , bool graph[101][101], vector<int> &col, int m, int n){
        if(u == n) return true;
        
        for(int i = 0 ; i < m ;i++){
            if(isSafe(u,i,n,graph,col)){
                col[u] = i;
                if(recc(u+1,graph,col,m,n)) return true;
                col[u] = -1;
            }
        }
        
        return false;
    }
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        vector<int>color(n,-1);
        return recc(0,graph,color,m,n);
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends