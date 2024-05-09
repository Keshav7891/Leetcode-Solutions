//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int Maximize(int arr[], int n)
        {
        // Complete the function
           long sum = 0;
             int given = 1000000007; // beacause return type is int not long
            if(n == 1){
                return 0;
            }
            sort(arr,arr+n);
            for(int i =0 ; i < n ; i++){
                 sum = (sum + (long) arr[i] * i) % given;
            }
            return (int)sum;
    }   
};

//{ Driver Code Starts.
int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<<ob.Maximize(a,n)<<endl;
    }
}
// } Driver Code Ends