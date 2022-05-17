class Solution {
public:
    void DFS(vector<vector<int>>& board, int i, int j, int newColor , int source)
    {
        int m = board.size();
        int n = board[0].size();
        if(i<0 || i>=m || j<0 || j>=n ||board[i][j] == newColor || board[i][j]!=source )
        {
            return;
        }
        board[i][j]=newColor;
        DFS(board,i-1,j,newColor,source);
        DFS(board,i+1,j,newColor,source);
        DFS(board,i,j-1,newColor,source);
        DFS(board,i,j+1,newColor,source);
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
    {
        int source = image[sr][sc];
        DFS(image,sr,sc,newColor,source);
        return image;
    }
};