class NumMatrix {
public:
    vector<vector<int>>grid;
    NumMatrix(vector<vector<int>>& matrix) {
        grid = matrix;
        for(int i=0;i<grid.size();i++)
        {
            int sum = 0;
            for(int j=0;j<grid[0].size();j++)
            {
                sum = sum + grid[i][j];
                grid[i][j] = sum;
            }
        }
        
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int xstart = col1 ;
        int xend = col2;
        int ystart = row1;
        int yend = row2;
        int res = 0;
        for(int i = ystart; i<= yend ;i++)
        {
            if(xstart!=0)
            {
                res = res + (grid[i][xend] - grid[i][xstart-1]);
            }
            else
            {
                res = res + (grid[i][xend]);
            }
        }
        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */