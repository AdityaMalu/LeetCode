class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        
        for (auto& preq : prerequisites) {
            adj[preq[1]].push_back(preq[0]); 
            indegree[preq[0]]++;
        }
        
        queue<int> q;
        
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        int count = 0;
        
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            count++;
            for (int next : adj[course]) {
                if (--indegree[next] == 0) {
                    q.push(next);
                }
            }
        }
        
        return count == numCourses;
    }
};
