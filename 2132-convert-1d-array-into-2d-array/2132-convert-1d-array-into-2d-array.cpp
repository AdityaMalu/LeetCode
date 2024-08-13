class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        if (original.size() != m * n)
            return {};
        for (int i = 1; i <= original.size(); i++) {
            if (i % n == 0) {
                temp.push_back(original[i - 1]);
                ans.push_back(temp);
                temp.clear();
                continue;
            }
            temp.push_back(original[i - 1]);
        }

        return ans;
    }
};