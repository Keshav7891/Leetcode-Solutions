//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        unordered_map<int,list<int>>adj;
        for(auto key : edges)
        {
            int u = key[0];
            int v = key[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int>q;
        vector<int>dist(N,1e9);
        dist[src] = 0;
        q.push(src);
        while(q.empty()==false)
        {
            auto curr = q.front();
            q.pop();
            
            for(auto nbr : adj[curr])
            {
                if(dist[curr]+1 < dist[nbr])
                {
                    dist[nbr] = dist[curr]+1;
                    q.push(nbr);
                }
            }
        }
        for(int i=0;i<dist.size();i++)
        {
            if(dist[i] == 1e9)
            {
                dist[i] = -1;
            }
        }
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends