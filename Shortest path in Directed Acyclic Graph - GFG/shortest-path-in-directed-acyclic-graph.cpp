//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     void help(int node , unordered_map<int,list<pair<int,int>>>& adj , unordered_map<int,bool>&visited,stack<int>&s)
     {
         visited[node] = true;
         for(auto key : adj[node])
         {
             int nbr = key.first;
             if(visited[nbr]!=true)
             {
                 help(nbr,adj,visited,s);
             }
         }
         s.push(node);
     }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        unordered_map<int,list<pair<int,int>>>adj;
        for(auto key : edges)
        {
            int u = key[0];
            int v = key[1];
            int wt = key[2];
            adj[u].push_back({v,wt});
        }
        stack<int>s;
        unordered_map<int,bool>visited;
        for(int i=0;i<N;i++)
        {
            if(visited[i]!=true)
            {
                help(i,adj,visited,s);
            }
        }
        int source = 0;
        vector<int>dist(N,1e9);
        dist[source] = 0;
        while(s.empty()==false)
        {
            int curr = s.top();
            s.pop();
            
            for(auto key : adj[curr])
            {
                int nbr = key.first;
                int wt = key.second;
                if(dist[curr] + wt < dist[nbr])
                {
                    dist[nbr] = dist[curr] + wt;
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends