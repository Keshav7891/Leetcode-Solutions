class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& grid) {
        for(int i=1;i<grid.size();i++)
        {
            for(int j=1;j<grid[0].size();j++)
            {
                if(grid[i][j]!=grid[i-1][j-1])
                {
                    return false;
                }
            }
        }
        return true;
    }
};