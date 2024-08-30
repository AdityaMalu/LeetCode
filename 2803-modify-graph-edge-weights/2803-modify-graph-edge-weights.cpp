class Solution {
public:
    void dijkstra(const vector<vector<pair<int, int>>>& adj,
                  vector<vector<int>>& edges, vector<vector<int>>& dist,
                  int src, int diff, int run) {
        int n = adj.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, src});
        dist[src][run] = 0;

        while (!pq.empty()) {
            auto [currDist, currNode] = pq.top();
            pq.pop();

            if (currDist > dist[currNode][run])
                continue;

            for (auto& n : adj[currNode]) {
                int nxtNode = n.first, edge = n.second;
                int wt = edges[edge][2];

                if (wt == -1)
                    wt = 1;

                if (run == 1 && edges[edge][2] == -1) {
                    int newWt = diff + dist[nxtNode][0] - dist[currNode][1];
                    if (newWt > wt) {
                        edges[edge][2] = wt = newWt;
                    }
                }

                if (dist[nxtNode][run] > dist[currNode][run] + wt) {
                    dist[nxtNode][run] = dist[currNode][run] + wt;
                    pq.push({dist[nxtNode][run], nxtNode});
                }
            }
        }
    }
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges,
                                           int source, int destination,
                                           int target) {
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            int A = edges[i][0], B = edges[i][1];
            adj[A].emplace_back(B, i);
            adj[B].emplace_back(A, i);
        }

        vector<vector<int>> dist(n, vector<int>(2, INT_MAX));
        dist[source][0] = dist[source][1] = 0;

        dijkstra(adj, edges, dist, source, 0, 0);
        int diff = target - dist[destination][0];
        if (diff < 0)
            return {};
        dijkstra(adj, edges, dist, source, diff, 1);
        if (dist[destination][1] < target)
            return {};

        for (auto& edge : edges) {
            if (edge[2] == -1)
                edge[2] = 1;
        }
        return edges;
    }
};