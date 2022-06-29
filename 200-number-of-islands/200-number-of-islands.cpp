class Solution {
public:
    void dfs(int x , int y , vector<vector<char>>& grid)
    {
        if(x<0 || x>=grid.size() || y<0 || y>=grid[0].size() || grid[x][y]!='1')
        {
            return;
        }
        grid[x][y]=0;
        dfs(x-1,y,grid);
        dfs(x,y-1,grid);
        dfs(x+1,y,grid);
        dfs(x,y+1,grid);
        
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        int res = 0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1')
                {
                    dfs(i,j,grid);
                    res++;
                }
            }
        }
        return res;
    }
};