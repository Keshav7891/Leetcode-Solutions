class Solution {
public:
    vector<vector<string>>res;
    
    bool safe(int row, int col, vector<string> board, int n) {
        // check upper diagonal
        int duprow = row;
        int dupcol = col; 
        
        while(row >= 0 && col >= 0) {
            if(board[row][col] == 'Q') return false;
            row--;
            col--;
        }
        
        
        col = dupcol; 
        row = duprow;
        while(col>=0) {
            if(board[row][col] == 'Q') return false;
            col--; 
        }
    
        row = duprow;
        col = dupcol; 
        while(row<n && col>=0) {
            if(board[row][col] == 'Q') return false;
            row++;
            col--; 
        }
        
        return true; 
    }
    
    void fill(int col , vector<string>&board , int n)
    {
        if(col==n)
        {
            res.push_back(board);
            return;
        }
        
        for(int row=0;row<n;row++)
        {
            if(safe(row,col,board,n)==true)
            {
                board[row][col]='Q';
                fill(col+1,board,n);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        vector<string>board(n);
        string s(n,'.');
        for(int i = 0;i<n;i++) {
            board[i] = s; 
        }
        fill(0,board,n);
        return res;
    }
};