class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) 
    {
        vector<int>indegree(n,0);
        for(auto key : edges)
        {
            int src = key[0];
            int dest = key[1];
            indegree[dest]++;
        }
        vector<int>res;
        for(int i=0;i<indegree.size();i++)
        {
            if(indegree[i]==0)
            {
                res.push_back(i);
            }
        }
        return res;
        
    }
};