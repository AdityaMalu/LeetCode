class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> actual;
        int ans= 0;
        for(auto i : heights){
            actual.push_back(i);
        }
        sort(heights.begin(), heights.end());

        for (int i = 0 ; i < heights.size() ; i++){
            if(actual[i] != heights[i]){
                ans+=1;
            }
        }
        return ans;
    }
};