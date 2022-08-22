class Solution {
public:
    
    bool help(int row , int col , vector<vector<int>>&grid)
    {
        if(row<0 || row>=grid.size() || col<0 || col>=grid[0].size() || grid[row][col]!=-1)
        {
            return false;
        }
        return true;
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==0)
                {
                    q.push({i,j});
                }
                else
                {
                    grid[i][j] = - grid[i][j];
                }
            }
        }
        
        while(q.empty()==false)
        {
            int size = q.size();
            
            for(int i=0;i<size;i++)
            {
                auto curr = q.front();
                q.pop();
                
                int row = curr.first;
                int col = curr.second;
                
                int dx[4] = { 1, 0 , -1 , 0 };
                int dy[4] = { 0 , 1 , 0 ,-1};
                
                for(int dir = 0; dir<4; dir++)
                {
                    int x = row + dx[dir];
                    int y = col + dy[dir];
                    
                    bool check = help(x,y,grid);
                    
                    if(check == true)
                    {
                        grid[x][y] = grid[row][col]+1;
                        q.push({x,y});
                    }
                }
            }
        }
        
        return grid;
    }
};