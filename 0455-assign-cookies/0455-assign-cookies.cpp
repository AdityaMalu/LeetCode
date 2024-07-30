class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());

        int ans = 0;
        int i = g.size()-1, j = s.size()-1;
        while(i >= 0 && j >= 0){
            if(g[i] <= s[j]){
                ans++;
                j--;
            }
            i--;
        }

        return ans;

    }
};