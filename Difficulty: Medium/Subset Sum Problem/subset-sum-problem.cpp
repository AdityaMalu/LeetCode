//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:

    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false));
    
        for(int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }
    
        for(int ind = 1; ind <= n; ind++) {
            for(int currSum = 1; currSum <= sum; currSum++) {
                bool notPick = dp[ind-1][currSum];
                bool pick = false;
                if(currSum >= arr[ind-1]) {
                    pick = dp[ind-1][currSum - arr[ind-1]];
                }
                dp[ind][currSum] = pick || notPick;
            }
        }
    
        return dp[n][sum];
}
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends