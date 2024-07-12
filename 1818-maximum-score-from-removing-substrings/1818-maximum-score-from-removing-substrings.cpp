class Solution {
public:
    int maximumGain(string s, int x, int y) {
        stack<char> st1;
        int ans = 0;
        if (x > y) {
            // Process 'ab' pairs first
            for (char ch : s) {
                if (!st1.empty() && st1.top() == 'a' && ch == 'b') {
                    st1.pop();
                    ans += x;
                } else {
                    st1.push(ch);
                }
            }
            
            // Collect remaining characters back into s
            s.clear();
            while (!st1.empty()) {
                s += st1.top();
                st1.pop();
            }
            reverse(s.begin(), s.end());

            // Process 'ba' pairs
            for (char ch : s) {
                if (!st1.empty() && st1.top() == 'b' && ch == 'a') {
                    st1.pop();
                    ans += y;
                } else {
                    st1.push(ch);
                }
            }
        } else {
            // Process 'ba' pairs first
            for (char ch : s) {
                if (!st1.empty() && st1.top() == 'b' && ch == 'a') {
                    st1.pop();
                    ans += y;
                } else {
                    st1.push(ch);
                }
            }
            
            // Collect remaining characters back into s
            s.clear();
            while (!st1.empty()) {
                s += st1.top();
                st1.pop();
            }
            reverse(s.begin(), s.end());

            // Process 'ab' pairs
            for (char ch : s) {
                if (!st1.empty() && st1.top() == 'a' && ch == 'b') {
                    st1.pop();
                    ans += x;
                } else {
                    st1.push(ch);
                }
            }
        }
        return ans;
    }
};
