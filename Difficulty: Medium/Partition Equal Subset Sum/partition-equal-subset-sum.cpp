//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isSubsetSum(int arr[], int n, int sum) {
        vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false));
    
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }
    
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                if (arr[i-1] <= j) {
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
    
        return dp[n][sum];
    }
    
    int equalPartition(int N, int arr[]) {
        int total = 0;
        for (int i = 0; i < N; i++) {
            total += arr[i];
        }
    
        if (total % 2 != 0) return 0;
    
        return isSubsetSum(arr, N, total/2) ? 1 : 0;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends