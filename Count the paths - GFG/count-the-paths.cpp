//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int count = 0;
    int help(int node , int dest , unordered_map<int,list<int>>&adj , vector<bool>&visited)
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
	int possible_paths(vector<vector<int>>edges, int n, int s, int d){
	   
	   unordered_map<int,list<int>>adj;
	   for(auto key : edges)
	   {
	       int u = key[0];
	       int v = key[1];
	       adj[u].push_back(v);
	   }
	   vector<bool>visited(adj.size(),false);
	   int paths = help(s,d,adj,visited);
	   return paths;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, s, d;
		cin >> n >> m >> s >> d;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int u, v;
			cin >> u >> v;
			edges.push_back({u,v});
		}
		Solution obj;
		int ans = obj.possible_paths(edges, n, s, d);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends