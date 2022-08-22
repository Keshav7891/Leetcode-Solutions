class Solution {
public:
    
    
    void dfs(int node, unordered_map<int,list<int>>&adj , unordered_map<int,bool>&visited)
    {
        visited[node]=true;
        
        for(auto nbr : adj[node])
        {
            if(visited[nbr]==false)
            {
                dfs(nbr,adj,visited);
            }
        }
    }
    
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int,list<int>>adj;
        
        for(int i=0;i<isConnected.size();i++)
        {
            for(int j=0;j<isConnected[0].size();j++)
            {
                if(isConnected[i][j]==1)
                {
                    int u = i;
                    int v = j;
                    adj[u].push_back(v);
                    adj[v].push_back(u);
                }
            }
        }
        unordered_map<int,bool>visited;
        int res = 0;
        for(int i=0;i<adj.size();i++)
        {
            if(visited[i]==false)
            {
                res++;
                dfs(i,adj,visited);
            }
        }
        return res;
    }
};