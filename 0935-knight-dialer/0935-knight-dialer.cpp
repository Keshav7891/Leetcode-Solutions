class Solution {
public:
    const int mod = 1e9 + 7;
    int help(int i , int j , int moves , vector<vector<int>>& grid, vector<vector<vector<int>>>&dp)
    {
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j] == -1)
        {
            return 0;
        }
        if(moves == 0)
        {
            return 1;
        }
        if(dp[i][j][moves]!=-1)
        {
            return dp[i][j][moves];
        }
        int res = 0;
        res = (res + help(i-2,j+1,moves-1,grid,dp))%mod;
        res = (res + help(i-1,j+2,moves-1,grid,dp))%mod;
        res = (res + help(i+1,j+2,moves-1,grid,dp))%mod;
        res = (res + help(i+2,j+1,moves-1,grid,dp))%mod;
        res = (res + help(i-2,j-1,moves-1,grid,dp))%mod;
        res = (res + help(i-1,j-2,moves-1,grid,dp))%mod;
        res = (res + help(i+1,j-2,moves-1,grid,dp))%mod;
        res = (res + help(i+2,j-1,moves-1,grid,dp))%mod;
        return dp[i][j][moves] = res;
    }
    int knightDialer(int n) {
        vector<vector<int>>grid;
        grid.push_back({1,2,3});
        grid.push_back({4,5,6});
        grid.push_back({7,8,9});
        grid.push_back({-1,0,-1});
        int res = 0;
        vector<vector<vector<int>>>dp(grid.size()+1,vector<vector<int>>(grid[0].size()+1,vector<int>(n+1,-1)));
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                int path = help(i,j,n-1,grid,dp);
                res = (res + path)%mod;
            }
        }
        return res;
    }
};