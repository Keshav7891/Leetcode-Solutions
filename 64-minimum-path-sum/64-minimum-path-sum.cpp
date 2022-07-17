class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size()));
        for(int i=grid.size()-1;i>=0;i--)
        {
            for(int j=grid[0].size()-1;j>=0;j--)
            {
                if(i==grid.size()-1 && j==grid[0].size()-1)
                {
                    //cout<<"hi"<<endl;
                    dp[i][j]=grid[i][j];
                }
                else if(i==grid.size()-1)
                {
                    dp[i][j] = dp[i][j+1] + grid[i][j];
                }
                else if(j==grid[0].size()-1)
                {
                    dp[i][j] =dp[i+1][j] + grid[i][j];
                }
                else
                {
                    dp[i][j] = min(dp[i+1][j],dp[i][j+1]) + grid[i][j];
                }
            }
        }
        
        for(auto key:dp)
        {
            for(auto key1 :key)
            {
                cout<<key1<<" ";
            }
            cout<<endl;
        }
        
        return dp[0][0];
    }
};