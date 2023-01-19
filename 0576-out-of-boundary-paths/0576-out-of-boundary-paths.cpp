class Solution {
public:
    const int mod = 1e9 + 7;
    int help(int i , int j , int moves , int m , int n , vector<vector<vector<int>>>&dp)
    {
        if(moves < 0)
        {
            return 0;
        }
        if(i>=m || j>=n || i<0 || j<0)
        {
            if(moves>=0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        if(dp[i][j][moves]!=-1)
        {
            return dp[i][j][moves];
        }
        int res = 0;
        res = (res + help(i+1,j,moves-1,m,n,dp))%mod;
        res = (res + help(i,j+1,moves-1,m,n,dp))%mod;
        res = (res + help(i-1,j,moves-1,m,n,dp))%mod;
        res = (res + help(i,j-1,moves-1,m,n,dp))%mod;
        
        return dp[i][j][moves] = res%mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>>dp(m+1,vector<vector<int>>(n+1,vector<int>(maxMove+1,-1)));
        return help(startRow,startColumn,maxMove,m,n,dp);
    }
};