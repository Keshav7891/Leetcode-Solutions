class Solution {
public:
    int help(int row , int col , vector<vector<int>>& grid , vector<vector<int>>&dp)
    {
        if(row>=grid.size() || col>=grid[0].size())
        {
            return INT_MAX;
        }
        
        if(row==grid.size()-1 && col==grid[0].size()-1)
        {
            return grid[row][col];
        }
        
        if(dp[row][col]!=-1)
        {
            return dp[row][col];
        }
        
        int right =  help(row,col+1,grid,dp);
        int down =  help(row+1,col,grid,dp);
        
        return dp[row][col] = min(right,down) + grid[row][col];
        
    }
    int minPathSum(vector<vector<int>>& grid) {
        int row = 0;
        int col = 0;
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),-1));
        int res = help(row,col,grid,dp);
        return res;
    }
};