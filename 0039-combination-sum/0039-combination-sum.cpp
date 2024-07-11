class Solution {
public:
    void back(vector<int> &candidates, int target, int idx,vector<int> &path, int total,vector<vector<int>> &ans){
        if(total==target){
            ans.push_back(path);
            return;
        }
        if(total>target || idx>=candidates.size()){
            return;
        }
        path.push_back(candidates[idx]);
        back(candidates,target,idx,path,total+candidates[idx],ans);
        path.pop_back();
        back(candidates,target,idx+1,path,total,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> path;
        back(candidates,target,0,path,0,ans);
        return ans;
    }
};