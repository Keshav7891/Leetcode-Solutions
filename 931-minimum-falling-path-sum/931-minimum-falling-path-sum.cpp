class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        vector<vector<int>>dp(grid.size(),vector<int>(grid.size()));
        
        for(int i=grid.size()-1;i>=0;i--)
        {
            for(int j=grid[0].size()-1;j>=0;j--)
            {
                if(i==grid.size()-1)
                {
                    dp[i][j] = grid[i][j];
                }
                else if(j==0)
                {
                    dp[i][j] = min(dp[i+1][j],dp[i+1][j+1]) + grid[i][j];
                }
                else if(j==grid.size()-1)
                {
                    dp[i][j] = min(dp[i+1][j],dp[i+1][j-1]) + grid[i][j];
                }
                else
                {
                    dp[i][j] = min(dp[i+1][j],min(dp[i+1][j-1],dp[i+1][j+1])) + grid[i][j];
                }
            }
        }
        int res = INT_MAX;
        for(int j=0;j<grid.size();j++)
        {
            res = min(res,dp[0][j]);
        }
        return res;
    }
};