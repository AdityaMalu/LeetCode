class Solution {
public:
    void dfs(vector<vector<int>>& graph, vector<vector<int>>& paths,vector<int> path, int start, int dest){
        path.push_back(start);

        if(start == dest){
            paths.push_back(path);
            return;
        }


        for(auto it: graph[start]){
            dfs(graph,paths,path,it,dest);
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths;
        vector<int>path;
        if (graph.size()==0) return {};

        dfs(graph,paths,path,0,graph.size()-1);

        return paths;
    }
};