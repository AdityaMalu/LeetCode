class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> adjList;

        for (const auto& time : times) {
            adjList[time[0]].push_back({time[1], time[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n + 1, INT_MAX);  
        dist[k] = 0;  
        pq.push({0, k});
        
        while (!pq.empty()) {
            auto curr = pq.top();
            int dis = curr.first;
            int node = curr.second;
            pq.pop();

            if (dis > dist[node]) continue;

            for (auto it : adjList[node]) {
                int nei = it.first;
                int tim = it.second;
                if (dis + tim < dist[nei]) {
                    dist[nei] = dis + tim;
                    pq.push({dis + tim, nei});
                }
            }
        }

        int maxDist = 0;
        for (int i = 1; i <= n; ++i) {
            if (dist[i] == INT_MAX) return -1;  
            maxDist = max(maxDist, dist[i]);
        }

        return maxDist;
    }
};
