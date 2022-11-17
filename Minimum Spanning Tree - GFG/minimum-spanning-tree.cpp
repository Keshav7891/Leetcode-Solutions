//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DSU
{
    private:
        vector<int>size;
        vector<int>parent;
    public:
        DSU(int n)
        {
            size.resize(n+1,0);
            parent.resize(n+1);
            for(int i=0;i<=n;i++)
            {
                parent[i] = i;
            }
        }
        
        int findParent(int node)
        {
            if(node == parent[node])
            {
                return node;
            }
            return parent[node] = findParent(parent[node]);
        }
        
        void unionBySize(int u , int v)
        {
            int pu = findParent(u);
            int pv = findParent(v);
            
            if(pu == pv)
            {
                return;
            }
            
            if(size[pu] < size[pv])
            {
                size[pv] = size[pv] + size[pu];
                parent[pu] = pv;
            }
            else
            {
                size[pu] = size[pu] + size[pv];
                parent[pv] = pu;
            }
        }
        
};
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        DSU obj(V);
        
        vector<pair<int,pair<int,int>>>edges;
        for(int i=0;i<V;i++)
        {
            int u = i;
            for(auto key : adj[u])
            {
                int v = key[0];
                int wt = key[1];
                edges.push_back({wt,{u,v}});
            }
        }
        sort(edges.begin(),edges.end());
        int res = 0;
        for(auto key : edges)
        {
            int wt = key.first;
            int u = key.second.first;
            int v = key.second.second;
            
            int pu = obj.findParent(u);
            int pv = obj.findParent(v);
            
            if(pu != pv)
            {
                res = res + wt;
                obj.unionBySize(u,v);
            }
        }
        return res;
        
        // code here
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends