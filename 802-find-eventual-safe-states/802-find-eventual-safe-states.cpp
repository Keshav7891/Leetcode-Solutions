class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        unordered_map<int,list<int>>adj;
        vector<int>indegree(graph.size(),0);
        
        for(int i=0;i<graph.size();i++)
        {
            for(auto key : graph[i])
            {
                adj[key].push_back(i);
                indegree[i]++;
            }
        }
        
        queue<int>q;
        for(int i=0;i<graph.size();i++)
        {
            int key = indegree[i];
            if(key==0)
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
        sort(res.begin(),res.end());
        return res;
        
    }
};