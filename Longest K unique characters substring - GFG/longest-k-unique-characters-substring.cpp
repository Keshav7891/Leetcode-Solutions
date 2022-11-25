//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        
        int j = 0;
        int res = -1;
        unordered_map<char,int>m;
        for(int i=0;i<s.size();i++)
        {
            char curr = s[i];
            m[curr]++;
            if(m.size()<k)
            {
                continue;
            }
            else if(m.size() == k)
            {
                res = max(res,i-j+1);
            }
            else
            {
                while(m.size()!=k)
                {
                    char temp = s[j];
                    m[temp]--;
                    j++;
                    if(m[temp] == 0)
                    {
                        m.erase(temp);
                    }
                }
                res = max(res,i-j+1);
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
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends