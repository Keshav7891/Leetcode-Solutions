class Solution {
public:
    int help(int x , int y , vector<vector<int>>&dp)
    {
        if(x==0 && y==0)
        {
            return 1;
        }
        if(x<0 || y<0)
        {
            return 0;
        }
        if(dp[x][y]!=-1)
        {
            return dp[x][y];
        }
        int left = help(x,y-1,dp);
        int up = help(x-1,y,dp);
        return dp[x][y] = left + up;
    }
    int uniquePaths(int m, int n) 
    {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        int res = help(m-1,n-1,dp);
        return res;
    }
};