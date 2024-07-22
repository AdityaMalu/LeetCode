class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       unordered_map<int,vector<int>> adjList;
       vector<int>inorder(numCourses,0);
        for (int i = 0; i < prerequisites.size(); i++) {
            int course = prerequisites[i][0];
            int prerequisite = prerequisites[i][1];
            adjList[prerequisite].push_back(course);
            inorder[course]++;
        }

       queue<int> q;
        int cnt = 0;
       for(int i = 0 ; i <  inorder.size() ; i++){
            if(inorder[i] == 0){
                q.push(i);
            }
       }

       while(!q.empty()){
        int curr = q.front();
        q.pop();
        cnt++;
        for(auto it : adjList[curr]){
            inorder[it]--;
            if(inorder[it] == 0){
                q.push(it);
            }
        }

       }
        return numCourses == cnt;        
    }
};
