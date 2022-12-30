class Solution {
public:
    vector<vector<int>>res;
    void dfs(int node , int dest , vector<int>path , unordered_map<int,bool>&visited , vector<vector<int>>& adj)
    {
        path.push_back(node);
        visited[node] = true;
        
        if(node == dest)
        {
            res.push_back(path);
        }
        
        for(auto nbr : adj[node])
        {
            if(visited[nbr]==false)
            {
                dfs(nbr,dest,path,visited,adj);
            }
        }
        
        visited[node] = false;
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        int node = 0;
        int dest = graph.size()-1;
        unordered_map<int,bool>visited;
        vector<int>path;
        dfs(node,dest,path,visited,graph);
        return res;
    }
};