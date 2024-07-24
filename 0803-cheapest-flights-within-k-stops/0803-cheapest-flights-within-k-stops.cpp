class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<pair<int,int>>> mp;
        for(auto i : flights){
            mp[i[0]].push_back({i[1],i[2]});
        }

        vector<int> dist(n,INT_MAX);
        dist[src] = 0;
        queue<pair<pair<int,int>,int>> q;
        q.push({{src,0},0});
        while(!q.empty()){
            auto curr = q.front();
            int src = curr.first.first;
            int dis = curr.first.second;
            int stops = curr.second;
            q.pop();

            if(stops > k){
                continue;
            }

            for(auto it : mp[src]){
                int neigh = it.first;
                int wt = it.second;
                if(dist[src] + wt < dist[neigh]){
                    dist[neigh] = dis + wt;
                    q.push({{neigh,dist[neigh]},stops+1});
                }
            }
        }
        
        if(dist[dst] == INT_MAX) return -1;
        return dist[dst];
    }
};