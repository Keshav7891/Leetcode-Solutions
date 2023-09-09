class Solution {
public:
    void dfs(int i, int j , vector<vector<int>>& grid ,  vector<vector<bool>>&visited , int source , int target){
        if(i<0 || j<0 || i>= grid.size() || j>=grid[0].size() || visited[i][j]==true || grid[i][j]!=source){
            return;
        }
        visited[i][j] = true;
        grid[i][j] = target;
        dfs(i+1,j,grid,visited,source,target);
        dfs(i-1,j,grid,visited,source,target);
        dfs(i,j+1,grid,visited,source,target);
        dfs(i,j-1,grid,visited,source,target);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int source = image[sr][sc];
        int target = color;
        vector<vector<bool>>visited(image.size(),vector<bool>(image[0].size(),false));
        dfs(sr,sc,image,visited,source,target);
        return image;
    }
};