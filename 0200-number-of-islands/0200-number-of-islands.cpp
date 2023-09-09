class Solution {
public:
    void dfs(int i, int j , vector<vector<char>>& grid ,  vector<vector<bool>>&visited){
        if(i<0 || j<0 || i>= grid.size() || j>=grid[0].size() || visited[i][j]==true || grid[i][j]!='1'){
            return;
        }
        visited[i][j] = true;
        dfs(i+1,j,grid,visited);
        dfs(i-1,j,grid,visited);
        dfs(i,j+1,grid,visited);
        dfs(i,j-1,grid,visited);
    }
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        vector<vector<bool>>visited(grid.size(),vector<bool>(grid[0].size(),false));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(visited[i][j] == false && grid[i][j] == '1'){
                    res++;
                    dfs(i,j,grid,visited);
                }
            }
        }
        return res;
    }
};