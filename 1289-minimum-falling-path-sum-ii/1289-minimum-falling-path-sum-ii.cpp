class Solution {
public:
    int help(int index , int picked , vector<vector<int>>& grid , vector<vector<int>>&dp)
    {
        if(index == grid.size())
        {
            return 0;
        }
        if(dp[index][picked]!=-1)   return dp[index][picked];
        int res = INT_MAX;
        for(int i=0;i<grid[index].size();i++)
        {
            if(i!=picked)
            {
               res  = min(res,grid[index][i] + help(index+1,i,grid,dp));
            }
        }
        return dp[index][picked] = res;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        vector<vector<int>>dp(grid.size()+1,vector<int>(grid[0].size()+2,-1));
        return help(0,grid.size()+1,grid,dp);
    }
};