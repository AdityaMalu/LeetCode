//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        string ans = arr[0];
        for(auto i : arr){
            string s =i;
            ans = check(ans,i);
        }
        
        if(ans.size() == 0) return "-1";
        return ans;
    }
    
    string check(string &s1, string &s2){
        int i =0, j=0;
        string ans="";
        while(i < s1.size() && s2.size()){
            if(s1[i] == s2[j]) ans += s1[i];
            else break;
            i++;
            j++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends