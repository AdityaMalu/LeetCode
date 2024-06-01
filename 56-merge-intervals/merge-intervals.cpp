class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin() , intervals.end());
        vector<vector<int>>ans;
        ans.push_back(intervals[0]);
        for(int i = 1 ; i < intervals.size();i++){
            vector<int>& curr = ans.back();
            if(intervals[i][0] <= curr[1])
            {
                curr[1] = max(intervals[i][1], curr[1]);
            }
            else{
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};