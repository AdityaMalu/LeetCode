class Solution {
public:
    string replaceContinuousZeros(string &str) {
        string result;
        bool inZeroSequence = false;

        for (char c : str) {
            if (c == '0') {
                if (!inZeroSequence) {
                    result += '0';
                    inZeroSequence = true;
                }
            } else {
                result += c;
                inZeroSequence = false;
            }
        }

        return result;
    }

    int maxOperations(string s) {
        string result;
        int onesCount = 0;
        int totalOnesBeforeZeros = 0;
        bool inZeroSequence = false;

        for (char c : s) {
            if (c == '0') {
                if (!inZeroSequence) {
                    result += '0';
                    inZeroSequence = true;
                    totalOnesBeforeZeros += onesCount;
                }
            } else {
                result += c;
                inZeroSequence = false;
                if (c == '1') {
                    onesCount++;
                }
            }
        }

        return totalOnesBeforeZeros;
    }
};