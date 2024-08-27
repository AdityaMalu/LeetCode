class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int,vector<pair<int,double>>> adj;

        for(int i = 0 ; i < edges.size() ; i++){
            adj[edges[i][0]].push_back({edges[i][1] ,succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }

        vector<double> vis(n,0);
        priority_queue<pair<double,int>> pq;

        vis[start_node] = 1;

        pq.push({1.0,start_node});
        while(!pq.empty()){

            double curr = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(node == end_node){
                return curr;
            }

            for(auto i : adj[node]){
                int nxt = i.first;
                double prob = i.second;

                if(curr*prob > vis[nxt]){
                    vis[nxt] = curr*prob;
                    pq.push({vis[nxt],nxt});
                }
            }
        }

        return 0.0;
    }
};