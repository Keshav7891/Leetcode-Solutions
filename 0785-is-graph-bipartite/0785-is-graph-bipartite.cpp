class Solution {
public:
    
    bool help(int src , unordered_map<int,int>&color , vector<vector<int>>&adj){
        color[src] = 1;
        queue<int>q;
        q.push(src);
        
        while(q.empty()==false){
            int size = q.size();
            for(int i=0;i<size;i++){
                auto curr = q.front();
                q.pop();
                
                for(auto nbr : adj[curr]){
                    if(color.find(nbr)==color.end()){
                        color[nbr] = !color[curr];
                        q.push(nbr);
                    }else if(color[nbr] == color[curr]){
                        return false;
                    }
                }
            }
        }
        
        return true;
    }
    
    
    bool isBipartite(vector<vector<int>>& graph) {
        unordered_map<int,int>color;
        for(int i=0;i<graph.size();i++){
            if(color.find(i)==color.end()){
                bool check = help(i,color,graph);
                if(check == false){
                    return false;
                }
            }
        }
        return true;
    }
};