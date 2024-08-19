class Solution {
public:
    int recc(int n, int curr, int clipboard){
        if(curr == n){
            return 0;
        }

        if(curr > n){
            return INT_MAX;
        }

        int paste = INT_MAX;
        if(clipboard > 0 && curr + clipboard <= n){
            int pasteResult = recc(n, curr + clipboard, clipboard);
            if (pasteResult != INT_MAX) {
                paste = 1 + pasteResult;
            }
        }

        int copy = INT_MAX;
        if(curr != clipboard){
            int copyResult = recc(n, curr, curr);
            if (copyResult != INT_MAX) {
                copy = 1 + copyResult;
            }
        }

        return min(copy, paste);
    }

    int minSteps(int n) {
        if (n == 1) return 0; 
        return recc(n, 1, 0);
    }
};
