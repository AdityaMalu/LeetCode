class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> factorial(n, 1);
        for (int i = 1; i < n; ++i) {
            factorial[i] = factorial[i - 1] * i;
        }

        string numbers = "";
        for (int i = 1; i <= n; ++i) {
            numbers += (char)('0' + i);
        }
        
        k--;

        string result = "";
        for (int i = n - 1; i >= 0; --i) {
            int index = k / factorial[i];
            result += numbers[index];
            numbers.erase(numbers.begin() + index);
            k %= factorial[i];
        }

        return result;
    }
};