class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        if (rows == 0) return 0;
        int cols = grid[0].size();
        
        int maxArea = 0;
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    int area = dfs(i, j, grid);
                    maxArea = max(maxArea, area);
                }
            }
        }
        
        return maxArea;
    }
    
private:
    int dfs(int i, int j, vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] != 1) {
            return 0;
        }
        
        grid[i][j] = 2;
        
        int area = 1;
        area += dfs(i - 1, j, grid);
        area += dfs(i + 1, j, grid);
        area += dfs(i, j - 1, grid);
        area += dfs(i, j + 1, grid);
        
        return area;
    }
};
