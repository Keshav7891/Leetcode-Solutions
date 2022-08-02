class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        unordered_map<int,unordered_set<int>> m;
        
        // making an adjacency list of  {element --> route in which it is present}
        for(int i=0;i<routes.size();i++){
            for(int j=0;j<routes[i].size();j++){
                m[routes[i][j]].insert(i);
            }
        }
        queue<pair<int,int>> q; // stores current element and no. of buses to reach that element
        q.push({S,0});
        unordered_set<int> set;
        set.insert(S);
        
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            int cur_stop = p.first;
            int bus_taken = p.second;
            if(cur_stop == T) // if cur stop is the final stop we return it
                return bus_taken;
            for(int route : m[cur_stop]){ // we go to all the routes in which cur_stop is present
                for(int r:routes[route]){
                    if(set.find(r) == set.end()){
                        q.push({r,bus_taken + 1});
                    }
                }
                
                routes[route].clear();
            }
        }
        return -1;
    }
};