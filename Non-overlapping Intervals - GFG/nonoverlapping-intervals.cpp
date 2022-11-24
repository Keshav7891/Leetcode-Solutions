//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minRemoval(int N, vector<vector<int>> &intervals) {
        
        sort(intervals.begin(),intervals.end());
        int res=0;
        int check = intervals[0][1];
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0]<check)
            {
                res++;
                if(intervals[i][1]<=check)
                {
                    check=intervals[i][1];
                }
            }
            else
            {
                check=intervals[i][1];
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
        int N;
        cin >> N;

        vector<vector<int>> intervals(N, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        Solution obj;
        cout << obj.minRemoval(N, intervals) << endl;
    }
    return 0;
}
// } Driver Code Ends