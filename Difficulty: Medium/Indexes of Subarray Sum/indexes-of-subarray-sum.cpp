//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int> arr, int n, long long s) {
       int j = 0;
       int start = -1;
       int end = -1;
       long long sum = 0;
       for(int i=0;i<n;i++){
           sum = sum + arr[i];
           while(j<i && sum > s){
               sum = sum - arr[j];
               j++;
           }
           if(sum == s){
               start = j+1;
               end = i+1;
               break;
           }
       }
       if(start == -1 && end == -1){
           return {-1};
       }
       return {start, end};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long s;
        cin >> n >> s;
        vector<int> arr(n);
        // int arr[n];
        const int mx = 1e9;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> res;
        res = ob.subarraySum(arr, n, s);

        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends