class Solution {
public:
    double help(int k , int i , int j , int row , int col , vector<vector<vector<double>>>&dp)
    {
        if(i<0 || i>=row || j<0 || j>=col)
        {
            return 0;
        }
        if(k == 0)
        {
            return 1;
        }
        if(dp[k][i][j]!=-1)
        {
            return dp[k][i][j];
        }
        double possibilities = 0;
        possibilities = possibilities + help(k-1,i-2,j+1,row,col,dp);
        possibilities = possibilities + help(k-1,i-1,j+2,row,col,dp);
        possibilities = possibilities + help(k-1,i+1,j+2,row,col,dp);
        possibilities = possibilities + help(k-1,i+2,j+1,row,col,dp);
        possibilities = possibilities + help(k-1,i+2,j-1,row,col,dp);
        possibilities = possibilities + help(k-1,i+1,j-2,row,col,dp);
        possibilities = possibilities + help(k-1,i-1,j-2,row,col,dp);
        possibilities = possibilities + help(k-1,i-2,j-1,row,col,dp);
        double probablity = possibilities/8;
        return dp[k][i][j] = probablity;
    }
    double knightProbability(int n, int k, int row, int col) {
        vector<vector<vector<double>>> dp(k + 1, vector<vector<double>> (n + 1, vector<double>(n + 1, -1)));
        return help(k,row,col,n,n,dp);
    }
};