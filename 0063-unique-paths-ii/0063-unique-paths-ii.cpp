class Solution {
public:
    int help(int i , int j , vector<vector<int>>& grid , vector<vector<int>>&dp)
    {
        if(i == 0 && j == 0)
        {
            return 1;
        }
        if(i<0 || j<0 || grid[i][j]==1)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int op1 = help(i-1,j,grid,dp);
        int op2 = help(i,j-1,grid,dp);
        return dp[i][j] = op1 + op2;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        if(grid[grid.size()-1][grid[0].size()-1]==1 || grid[0][0]==1)    return 0;
        vector<vector<int>>dp(grid.size()+1,vector<int>(grid[0].size()+1,-1));
        return help(grid.size()-1,grid[0].size()-1,grid,dp);
    }
};