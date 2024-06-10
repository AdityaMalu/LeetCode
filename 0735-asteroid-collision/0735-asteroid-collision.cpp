class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk;
        for(int asteroid : asteroids) {
            bool destroyed = false;
            while(!stk.empty() && asteroid < 0 && stk.top() > 0) {
                if(abs(stk.top()) < abs(asteroid)) {
                    stk.pop();
                } else if(abs(stk.top()) == abs(asteroid)) {
                    stk.pop();
                    destroyed = true;
                    break;
                } else {
                    destroyed = true;
                    break;
                }
            }
            if(!destroyed) {
                stk.push(asteroid);
            }
        }

        vector<int> ans;
        while(!stk.empty()) {
            ans.push_back(stk.top());
            stk.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};