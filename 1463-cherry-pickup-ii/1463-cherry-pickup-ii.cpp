class Solution {
public:
    int help(int j1 , int i , int j2 , vector<vector<int>>& grid,vector<vector<vector<int>>>&dp)
    {
        if(j1<0 || j2<0 || j1>=grid[0].size() || j2>=grid[0].size())
        {
            return INT_MIN;
        }
        if(i==grid.size()-1)
        {
            if(j1==j2)
            {
                return grid[i][j1];
            }
            else
            {
                return grid[i][j1] + grid[i][j2];
            }
        }
        if(dp[j1][i][j2]!=-1)
        {
            return dp[j1][i][j2];
        }
        int res = INT_MIN;
        for(int dj1=-1;dj1<=1;dj1++)
        {
            for(int dj2=-1;dj2<=1;dj2++)
            {
                int total = 0;
                if(j1==j2)
                {
                    total = grid[i][j1];
                }
                else
                {
                    total = grid[i][j1] + grid[i][j2];
                }
                total = total + help(j1+dj1,i+1,j2+dj2,grid,dp); 
                res = max(res,total);
            }
        }
        return dp[j1][i][j2] = res;
    }
    int cherryPickup(vector<vector<int>>& grid) 
    {
        vector<vector<vector<int>>> dp(grid[0].size()+1, vector<vector<int>>(grid.size()+1, vector<int>(grid[0].size()+1, -1)));
        int res = help(0,0,grid[0].size()-1,grid,dp);
        return res;
    }
};