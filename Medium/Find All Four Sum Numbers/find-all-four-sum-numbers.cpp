//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &nums, int k) {
       sort(nums.begin(),nums.end());
       vector<vector<int>>res;
       for(int i=0;i<nums.size();i++){
           if(i>0 && nums[i] == nums[i-1]){
               continue;
           }
           for(int j=i+1;j<nums.size();j++){
               if(j>i+1 && nums[j] == nums[j-1]){
                   continue;
               }
               int low = j+1;
               int high = nums.size()-1;
               while(low<high){
                   int sum = nums[i] + nums[j] + nums[low] + nums[high];
                   if(sum == k){
                       res.push_back({nums[i], nums[j], nums[low], nums[high]});
                       low++;
                       high--;
                       while(low<high && nums[low] == nums[low-1]) low++;
                       while(low<high && nums[high] == nums[high+1]) high--;
                   }else if(sum > k){
                       high--;
                   }else{
                       low++;
                   }
               }
           }
       }
       return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends