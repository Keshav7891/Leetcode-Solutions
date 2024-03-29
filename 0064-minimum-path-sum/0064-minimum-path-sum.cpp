class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size()+1,-1));
        for(int i=grid.size()-1;i>=0;i--)
        {
            for(int j=grid[0].size()-1;j>=0;j--)
            {
                if(i == grid.size()-1 && j == grid[0].size()-1)
                {
                    dp[i][j] = grid[i][j];
                }
                else if(i == grid.size()-1)
                {
                    dp[i][j] = grid[i][j] + dp[i][j+1];
                }
                else if(j == grid[0].size()-1)
                {
                    dp[i][j] = grid[i][j] + dp[i+1][j];
                }
                else
                {
                    dp[i][j] = grid[i][j] + min(dp[i][j+1],dp[i+1][j]);
                }
            }
        }
        return dp[0][0];
    }
};