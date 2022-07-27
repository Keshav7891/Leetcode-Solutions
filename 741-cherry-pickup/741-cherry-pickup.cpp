class Solution {
public:
    int help(int r1 , int c1 , int r2 , int c2 , vector<vector<int>>&grid , vector<vector<vector<vector<int>>>>&dp)
    {
        if(r1>=grid.size() || r2>=grid.size() || c1>=grid[0].size() || c2>=grid[0].size() || grid[r1][c1]==-1 || grid[r2][c2]==-1)
        {
            return INT_MIN;
        }
        if(r1==grid.size()-1 && c1==grid[0].size()-1)
        {
            return grid[r1][c1];
        }
        if(dp[r1][c1][r2][c2]!=-1)
        {
            return dp[r1][c1][r2][c2];
        }
        int cherry = 0;
        if(r1==r2 && c1==c2)
        {
            cherry = cherry + grid[r1][c1];
        }
        else
        {
            cherry = cherry + (grid[r1][c1] + grid[r2][c2]);
        }
        
        int hh = help(r1,c1+1,r2,c2+1,grid,dp);
        int hv = help(r1,c1+1,r2+1,c2,grid,dp);
        int vh = help(r1+1,c1,r2,c2+1,grid,dp);
        int vv = help(r1+1,c1,r2+1,c2,grid,dp);

        cherry = cherry + max({hh,hv,vh,vv});
        return dp[r1][c1][r2][c2] = cherry;
    }
    int cherryPickup(vector<vector<int>>& grid) 
    {
        vector<vector<vector<vector<int>>>>dp(grid.size()+1,vector<vector<vector<int>>>(grid.size()+1,vector<vector<int> >(grid.size()+1,vector<int>(grid.size()+1,-1))));
        int res = help(0,0,0,0,grid,dp);
        if(res<0)
        {
            return 0;
        }
        return res;
    }
};