class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,list<int>>adj;
        vector<int>indegree(numCourses,0);
        
        for(auto key : prerequisites)
        {
            int u = key[0];
            int v = key[1];
            
            adj[u].push_back(v);
            indegree[v]++;
        }
        
        queue<int>q;
        for(int i=0;i<indegree.size();i++)
        {
            int key = indegree[i];
            if(key==0)
            {
                q.push(i);
            }
        }
        
        int cnt = 0;
        while(q.empty()==false)
        {
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                auto curr = q.front();
                q.pop();
                cnt++;
                for(auto key : adj[curr])
                {
                    indegree[key]--;
                    if(indegree[key]==0)
                    {
                        q.push(key);
                    }
                }
            }
        }
        return (cnt==numCourses);
        
    }
};