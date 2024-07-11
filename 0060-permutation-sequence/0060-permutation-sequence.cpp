class Solution {
public:
    string getPermutation(int n, int k) {
        string temp = "";
        char c = '1';
        for(int i = 0 ; i <n ; i++){
            temp += c;
            c++;
        }
        for(int i =0 ; i < k-1 ; i++){
            next_permutation(temp.begin(),temp.end());
        }
        return temp;

    }
};