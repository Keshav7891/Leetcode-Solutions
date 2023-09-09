class Solution {
public:
    /*
    1 1 0
    1 1 0
    0 0 1
    */
    void help(int curr,unordered_map<int,bool>&visited,unordered_map<int,vector<int>>&adj){
        visited[curr] = true;
        for(auto nbr : adj[curr]){
            if(visited[nbr] == false){
                help(nbr,visited,adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected[i].size();j++){
                if(isConnected[i][j] == 1 && i!=j){
                    int u = i;
                    int v = j;
                    adj[u].push_back(v);
                    adj[v].push_back(u);
                }
            }
        }
        int res = 0;
        unordered_map<int,bool>visited;
        for(int i=0;i<isConnected.size();i++){
            if(visited[i] == false){
                res++;
                help(i,visited,adj);
            }
        }
        return res;
    }
};