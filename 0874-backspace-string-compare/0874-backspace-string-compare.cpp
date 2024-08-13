class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.length() - 1, j = t.length() - 1;
        int skipS = 0, skipT = 0;

        while (i >= 0 || j >= 0) {
            i = nextValidCharIndex(s, i, skipS);
            j = nextValidCharIndex(t, j, skipT);

            if (i >= 0 && j >= 0 && s[i] != t[j])
                return false;
            if ((i >= 0) != (j >= 0))
                return false;

            i--;
            j--;
        }
        return true;
    }

private:
    int nextValidCharIndex(const string& str, int index, int& skip) {
        while (index >= 0) {
            if (str[index] == '#') {
                skip++;
            } else if (skip > 0) {
                skip--;
            } else {
                break;
            }
            index--;
        }
        return index;
    }
};
