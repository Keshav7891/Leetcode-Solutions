class Solution {
public:
    void DFS(int i , int j , vector<vector<int>>&grid ,int &gold, int path)
    {
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j] == 0)
        {
            gold = max(path,gold);
            return;
        }
        
        int temp = grid[i][j];
        grid[i][j]=0;
        path=path+temp;
        
        DFS(i+1,j,grid,gold,path);
        DFS(i-1,j,grid,gold,path);
        DFS(i,j+1,grid,gold,path);
        DFS(i,j-1,grid,gold,path);
        
        grid[i][j]=temp;
        
    }
    int getMaximumGold(vector<vector<int>>& grid)
    {
        int res = 0;
        int gold = 0;
        int path = 0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]!=0)
                {
                    DFS(i,j,grid,gold,path);
                }
                res=max(res,gold);
                gold=0;
                path=0;
            }
        }
        return res;
    }
};