class Solution {
public:
    void dfs(int node,vector<bool>&visited,unordered_map<int,list<int>>&adj)
    {
        visited[node] = true;
        for(auto nbr : adj[node])
        {
            if(visited[nbr]==false)
            {
                dfs(nbr,visited,adj);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections)
    {
        int k=connections.size();
        if(k<n-1)
        {
            return -1;
        }
        unordered_map<int,list<int>>adj;
        for(auto key : connections)
        {
            int u = key[0];
            int v = key[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int res=0;
        vector<bool>visited(n,false);
        for(int i=0;i<n;i++)
        {
            if(visited[i]==false)
            {
                dfs(i,visited,adj);
                res++;
            }
        }
        return res-1;
    }
};