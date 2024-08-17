class Solution {
public:
    void recc(string &s, int ind, vector<string> &ans) {
        if (ind == s.size()) {
            ans.push_back(s);
            return;
        }

        recc(s, ind + 1, ans);

        if ((s[ind] >= 'a' && s[ind] <= 'z') || (s[ind] >= 'A' && s[ind] <= 'Z')) {
            if (islower(s[ind])) {
                s[ind] = toupper(s[ind]);
                recc(s, ind + 1, ans);
                s[ind] = tolower(s[ind]);
            } else if (isupper(s[ind])) {
                s[ind] = tolower(s[ind]);
                recc(s, ind + 1, ans);
                s[ind] = toupper(s[ind]);
            }
        }
    }

    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        recc(s, 0, ans);
        return ans;
    }
};
