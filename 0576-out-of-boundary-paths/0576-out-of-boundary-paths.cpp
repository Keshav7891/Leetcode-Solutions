class Solution {
public:
    int dp[51][51][52];
    const int mod = 1e9 + 7;
    int help(int i , int j , int moves , int m , int n)
    {
        if(i==m || j==n || i<0 || j<0)  return 1; 
        if(moves==0)                    return 0; 
        if(dp[i][j][moves]!=-1)         return dp[i][j][moves];
        int res = 0;
        res = (res + help(i+1,j,moves-1,m,n))%mod;
        res = (res + help(i,j+1,moves-1,m,n))%mod;
        res = (res + help(i-1,j,moves-1,m,n))%mod;
        res = (res + help(i,j-1,moves-1,m,n))%mod;
        
        return dp[i][j][moves] = res%mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp,-1,sizeof(dp));
        return help(startRow,startColumn,maxMove,m,n);
    }
};