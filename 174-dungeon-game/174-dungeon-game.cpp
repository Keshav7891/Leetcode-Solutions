class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& grid) {
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size()));
        for(int i=grid.size()-1;i>=0;i--)
        {
            for(int j=grid[0].size()-1;j>=0;j--)
            {
                if(i==grid.size()-1 && j==grid[0].size()-1)
                {
                   dp[i][j] = min(0,grid[i][j]);
                }
                else if(i==grid.size()-1)
                {
                   dp[i][j] = min(0,grid[i][j] + dp[i][j+1]);
                }
                else if(j==grid[0].size()-1)
                {
                    dp[i][j] = min(0,grid[i][j] + dp[i+1][j]);
                }
                else
                {
                   dp[i][j] = min(0,max(grid[i][j]+dp[i+1][j] , grid[i][j]+dp[i][j+1]));
                }
            }
        }
        return abs(dp[0][0])+1;
    }
};