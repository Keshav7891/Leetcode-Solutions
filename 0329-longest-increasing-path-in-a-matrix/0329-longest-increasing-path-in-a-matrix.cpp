class Solution {
public:
    int help(int x , int y , int prev , vector<vector<int>>& matrix , vector<vector<int>>& dp)
    {
        if(x<0 || x>=matrix.size() || y<0 || y>=matrix[0].size() || prev>=matrix[x][y])
        {
            return 0;
        }
        if(dp[x][y]!=-1)
        {
            return dp[x][y];
        }
        int op1 = 1 + help(x-1,y,matrix[x][y],matrix,dp);
        int op2 = 1 + help(x+1,y,matrix[x][y],matrix,dp);
        int op3 = 1 + help(x,y-1,matrix[x][y],matrix,dp);
        int op4 = 1 + help(x,y+1,matrix[x][y],matrix,dp);
        return dp[x][y] = max({op1,op2,op3,op4});
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>>dp(matrix.size()+1,vector<int>(matrix[0].size()+1,-1));
        int res = 0;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                int path = help(i,j,-1,matrix,dp);
                res = max(res,path);
            }
        }
        return res;
    }
};