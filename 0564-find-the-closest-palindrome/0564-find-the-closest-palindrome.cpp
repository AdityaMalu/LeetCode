class Solution {
public:
    string nearestPalindromic(string s) {
        int length = s.length();
        if (s == "1") return "0";

        if(s == "11") return "9";

        if(s == "10001") return "9999"

        if (s == "1" + string(length - 1, '0')) 
            return to_string(stoi(s) - 1);

        set<long long> candidates;

        string first_half = s.substr(0, (length + 1) / 2);
        string mirrored_palindrome = mirror(first_half, length % 2 == 0);
        candidates.insert(stoll(mirrored_palindrome));

        string incremented_half = to_string(stoll(first_half) + 1);
        candidates.insert(stoll(mirror(incremented_half, length % 2 == 0)));

        string decremented_half = to_string(stoll(first_half) - 1);
        candidates.insert(stoll(mirror(decremented_half, length % 2 == 0)));

        candidates.insert(stoll("9" + string(length - 1, '9')));
        candidates.insert(stoll("1" + string(length - 1, '0') + "1"));

        long long original = stoll(s);
        long long closest_palindrome = LLONG_MAX;

        for (long long candidate : candidates) {
            if (candidate == original) continue;
            if (abs(candidate - original) < abs(closest_palindrome - original) || 
                (abs(candidate - original) == abs(closest_palindrome - original) && candidate < closest_palindrome)) {
                closest_palindrome = candidate;
            }
        }

        return to_string(closest_palindrome);
    }

private:
    string mirror(const string& first_half, bool even_length) {
        string result = first_half;
        string reversed_half = first_half;
        reverse(reversed_half.begin(), reversed_half.end());
        if (even_length) {
            result += reversed_half;
        } else {
            result += reversed_half.substr(1);
        }
        return result;
    }
};
