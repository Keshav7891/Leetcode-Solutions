//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    
    int help(int index , int capacity, int weights[], int values[], int n, vector<vector<int>>&dp){
        
        if(capacity == 0){
            return 0;
        }else if(index == n){
            return 0;
        }
        
        if(dp[capacity][index] != -1){
            return dp[capacity][index];
        }
        
        int op1 = 0 + help(index+1,capacity,weights,values,n, dp);
        int op2 = INT_MIN;
        if(capacity - weights[index] >= 0){
            op2 = values[index] + help(index+1, capacity - weights[index], weights, values, n, dp);
        }
        
        return dp[capacity][index] = max(op1, op2);
        
    }
    
    int knapSack(int capacity, int weights[], int values[], int n) 
    { 
       vector<vector<int>>dp(capacity+1,vector<int>(n+1,-1));
       int res = help(0,capacity, weights, values, n, dp);
       return res;
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends