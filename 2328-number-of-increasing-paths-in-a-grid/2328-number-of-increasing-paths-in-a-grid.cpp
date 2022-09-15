class Solution {
public:
     const int mod = 1000000007;
    int dfs(int x , int y , vector<vector<int>>&grid , int prev , vector<vector<int>>&dp)
    {
        if(x<0 || y<0 || x>=grid.size() || y>=grid[0].size() || prev>=grid[x][y])
        {
            return 0;
        }
        if(dp[x][y]!=-1)
        {
            return dp[x][y];
        }
        int up = dfs(x-1,y,grid,grid[x][y],dp);
        int down = dfs(x+1,y,grid,grid[x][y],dp);
        int left = dfs(x,y-1,grid,grid[x][y],dp);
        int right = dfs(x,y+1,grid,grid[x][y],dp);
        return  dp[x][y] = (1+up+down+left+right)%mod;
    }
    int countPaths(vector<vector<int>>& grid) {
        int res = 0;
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),-1));
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                int path = dfs(i,j,grid,-1,dp);
                res = (res + path)%mod;
            }
        }
        return res;
    }
};