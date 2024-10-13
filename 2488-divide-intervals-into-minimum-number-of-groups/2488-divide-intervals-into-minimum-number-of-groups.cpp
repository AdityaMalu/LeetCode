class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int> s,e;
        for(auto i : intervals){
            s.push_back(i[0]);
            e.push_back(i[1]);
        }
        sort(s.begin(),s.end());
        sort(e.begin(),e.end());

        int ptr1 = 0, ptr2 = 0;
        for(auto i : s){
            if(i > e[ptr1]){
                ptr1++;
            }
            else{
                ptr2++;
            }
        }
        return ptr2;

    }
};