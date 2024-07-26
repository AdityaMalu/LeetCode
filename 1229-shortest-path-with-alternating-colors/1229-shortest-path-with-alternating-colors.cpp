class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int> adjRed[n], adjBlue[n];
        for(auto it : redEdges){
            adjRed[it[0]].push_back(it[1]);
        }
        for(auto it : blueEdges){
            adjBlue[it[0]].push_back(it[1]);
        }
        set<pair<int, int>> vis;
        vis.insert({0, -1});
        vector<int> ans(n, -1);
        queue<pair<int, pair<int, int>>> q; 
        q.push({0, {0, -1}});
        while(!q.empty()){
            int node = q.front().first;
            int length = q.front().second.first;
            int color = q.front().second.second;
            q.pop();
            if(ans[node] == -1){
                ans[node] = length;
            }
          
            if(color != 0){
                for(auto it : adjRed[node]){
                    if(vis.find({it, 0}) == vis.end()){
                        vis.insert({it, 0});
                        q.push({it, {length + 1, 0}});
                    }
                }
            }

            if(color != 1){
                for(auto it : adjBlue[node]){
                    if(vis.find({it, 1}) == vis.end()){
                        vis.insert({it, 1});
                        q.push({it, {length + 1, 1}});
                    }
                }
            }
        }
        return ans;
    }
};