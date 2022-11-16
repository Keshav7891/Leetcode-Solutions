//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to count paths between two vertices in a directed graph.
    int count = 0;
    int help(int node , int dest , vector<int> adj[] , vector<bool>&visited)
    {
        if(node == dest)
        {
            //cout<<"yes"<<endl;
            return 1;
        }
        visited[node] = true;
        int paths = 0;
        for(auto nbr : adj[node])
        {
            if(visited[nbr] == false)
            {
                paths = paths + help(nbr,dest,adj,visited);
            }
        }
        visited[node] = false;
        return paths;
    }
	
    int countPaths(int V, vector<int> adj[], int source, int destination) {
        // Code here
        vector<bool>visited(V,false);
	   int paths = help(source,destination,adj,visited);
	   return paths;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // adj[v].push_back(u);
        }
        int source, destination;
        cin >> source >> destination;
        Solution obj;
        cout << obj.countPaths(V, adj, source, destination) << endl;
    }
    return 0;
}
// } Driver Code Ends