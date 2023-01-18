class Solution {
public:
    int help(int index , int i , vector<vector<int>>& triangle , vector<vector<int>>&dp)
    {
        if(index == triangle.size())
        {
            return 0;
        }
        if(dp[index][i]!=-1)    return dp[index][i];
        int op1 = triangle[index][i] + help(index+1,i,triangle,dp);
        int op2 = triangle[index][i] + help(index+1,i+1,triangle,dp);
        return dp[index][i] = min(op1,op2);
    }
    int minimumTotal(vector<vector<int>>& grid) {
        vector<vector<int>>dp(grid.size()+1,vector<int>(grid[grid.size()-1].size()+1,-1));
        return help(0,0,grid,dp);
    }
};