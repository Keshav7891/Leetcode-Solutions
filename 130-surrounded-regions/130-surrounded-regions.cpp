class Solution {
public:
    
    void dfs(int row , int col , vector<vector<char>>&grid)
    {
        if(row<0 || row>=grid.size() || col<0 || col>=grid[0].size() || grid[row][col] !='O')
        {
            return ;
        }
        
        grid[row][col] = '$';
        
        dfs(row+1,col,grid);
        dfs(row-1,col,grid);
        dfs(row,col+1,grid);
        dfs(row,col-1,grid);
    }
    
    void solve(vector<vector<char>>& grid) 
    {
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(i==0||j==0||i==grid.size()-1||j==grid[0].size()-1)
                {
                    if(grid[i][j]=='O')
                    {
                        dfs(i,j,grid);
                    }
                }
            }
        }
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='$')
                {
                    grid[i][j]='O';
                }
                else if(grid[i][j]=='O')
                {
                    grid[i][j]='X';
                }
            }
        }
    }
};