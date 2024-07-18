class Solution {
public:
    void dfs(vector<vector<int>> &adj,vector<int> &vis,int city){
        vis[city] = 1;
        for(auto i : adj[city]){
            if(!vis[i]){
                dfs(adj,vis,i);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& connect) {
        vector<vector<int>> adj(connect.size());
        vector<int>vis(connect.size(),0);
        int ans = 0;

        for(int i = 0 ; i < connect.size() ; i++){
            for( int j = 0 ; j< connect.size() ; j++){
                if(i != j && connect[i][j] == 1){
                    adj[i].push_back(j);
                }
               
            }
        }


        for(int i = 0 ; i < adj.size() ; i++){
            if(!vis[i]){
                ans++;
                dfs(adj,vis,i);
            }
        }  

        return ans;  
    }
};