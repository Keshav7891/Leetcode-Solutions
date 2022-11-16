//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    vector<bool>visited(V,false);
	   queue<pair<int,int>>q;
	   q.push({0,0});
	   visited[0]=true;
	   while(q.empty()==false)
	   {
	       int size = q.size();
	       for(int i=0;i<size;i++)
	       {
	           auto curr = q.front();
	           q.pop();
	           
	           int node = curr.first;
	           int steps = curr.second;
	           
	           if(node == X)
	           {
	               return steps;
	           }
	           
	           for(auto nbr : adj[node])
	           {
	               if(visited[nbr]==false)
	               {
	                   visited[nbr] = true;
	                   q.push({nbr,steps+1});
	               }
	           }
	       }
	   }
	   return -1;
	   
	}
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}


// } Driver Code Ends