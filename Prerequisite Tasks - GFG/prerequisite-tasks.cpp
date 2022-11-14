//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector<int>indegree(N,0);
	    unordered_map<int,list<int>>adj;
	    for(auto key : prerequisites)
	    {
	        int u = key.first;
	        int v = key.second;
	        indegree[v]++;
	        adj[u].push_back(v);
	    }
	    queue<int>q;
	    for(int i=0;i<indegree.size();i++)
	    {
	        if(indegree[i]==0)
	        {
	            q.push(i);
	        }
	    }
	    vector<int>res;
	    while(q.empty()==false)
	    {
	        int size = q.size();
	        for(int i=0;i<size;i++)
	        {
	            auto curr = q.front();
	            q.pop();
	            res.push_back(curr);
	            for(auto nbr : adj[curr])
	            {
	                indegree[nbr]--;
	                if(indegree[nbr]==0)
	                {
	                    q.push(nbr);
	                }
	            }
	        }
	    }
	    if(res.size() == N)
	    {
	        return true;
	    }
	    else
	    {
	        return false;
	    }
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends