class Solution {
public:
    void dfs(int x , int y , int &area ,vector<vector<int>>& grid)
    {
        if(x<0 || x>=grid.size() || y<0 || y>=grid[0].size() || grid[x][y]!=1)
        {
            return;
        }
        grid[x][y]=0;
        area++;
        dfs(x-1,y,area,grid);
        dfs(x,y-1,area,grid);
        dfs(x+1,y,area,grid);
        dfs(x,y+1,area,grid);
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                int area = 0;
                if(grid[i][j]==1)
                {
                    dfs(i,j,area,grid);
                    res=max(res,area);
                }
            }
        }
        return res;
    }
};