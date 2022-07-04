class Solution {
public:
    int findCenter(vector<vector<int>>& edges) 
    {
        unordered_map<int,int>outdegree;
        for(auto key : edges)
        {
            int src = key[0];
            int dest = key[1];
            outdegree[src]++;
            outdegree[dest]++;
        }
        int n = outdegree.size();
        for(auto key : outdegree)
        {
            //cout<<key.first<<" "<<key.second<<endl;
            if(key.second == n-1)
            {
                return key.first;
            }
        }
        return -1;
    }
};