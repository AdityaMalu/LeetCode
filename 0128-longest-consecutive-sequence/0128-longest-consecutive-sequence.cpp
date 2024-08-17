class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0 || n ==1 ) return n;

        unordered_set<int> st;
        for(int i : nums) st.insert(i);

        int ans = 1;

        for(int i : st){
            if(st.find(i-1) == st.end()){
                int cnt = 0;
                while(st.find(i++) != st.end()){
                    cnt++;
                }
                ans = max(ans,cnt);
            }
        }

        return ans;
    }
};