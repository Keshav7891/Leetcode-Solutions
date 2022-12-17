class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int res = 0;
        vector<vector<int>>dp(matrix.size(),vector<int>(matrix[0].size()));
        for(int i=matrix.size()-1;i>=0;i--)
        {
            for(int j=matrix[0].size()-1;j>=0;j--)
            {
                if(i==matrix.size()-1 || j==matrix[0].size()-1)
                {
                    dp[i][j] = matrix[i][j];
                }
                else
                {
                    if(matrix[i][j] == 1)
                    {
                        int down = dp[i+1][j];
                        int right = dp[i][j+1];
                        int diaog = dp[i+1][j+1];
                        dp[i][j] = min({down,right,diaog})+1;
                    }
                }
                res = res + dp[i][j];
            }
        }
        return res;
    }
};