class Solution {
public:
    void rec(vector<int> &candidates, int target, int index, vector<int> &path,vector<vector<int>> &ans){
        if(target==0){
            ans.push_back(path);
            return;
        }

        for(int i = index; i <candidates.size() ; i++){
            if(i > index && candidates[i] == candidates[i-1]){
                continue;
            }
            if(candidates[i]>target){
                break;
            }
            path.push_back(candidates[i]);
            rec(candidates,target-candidates[i],i+1,path,ans);
            path.pop_back();
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> path;
        sort(candidates.begin(),candidates.end());
        rec(candidates,target,0,path,ans);
        return ans;
    }
};