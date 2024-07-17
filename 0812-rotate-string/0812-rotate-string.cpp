class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        string g = goal+goal;
        return g.find(s) != string::npos;
        
    }
};