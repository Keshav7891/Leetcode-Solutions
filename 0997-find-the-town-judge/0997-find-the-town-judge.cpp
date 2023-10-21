class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1){
            return 1;
        }
        if(trust.size()==0){
            return -1;
        }
        unordered_map<int,int>indegree;
        unordered_map<int,int>outdegree;
        for(auto key : trust){
            int u = key[0];
            int v = key[1];
            indegree[v]++;
            outdegree[u]++;
        }
        for(auto key : indegree){
            if(key.second == n-1 and outdegree[key.first]==0){
                return key.first;
            }
        }
        return -1;
    }
};