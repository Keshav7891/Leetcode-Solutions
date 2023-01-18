class Solution {
public:
    int help(int i , int j , int m , int n , vector<vector<int>>&dp)
    {
        if(i == m-1 && j == n-1)
        {
            return 1;
        }
        else if(i>=m || j>=n)
        {
            return 0;
        }
        if(dp[i][j]!=-1)    return dp[i][j];
        int op1 = help(i+1,j,m,n,dp);
        int op2 = help(i,j+1,m,n,dp);
        return dp[i][j] = op1 + op2;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return help(0,0,m,n,dp);
    }
};