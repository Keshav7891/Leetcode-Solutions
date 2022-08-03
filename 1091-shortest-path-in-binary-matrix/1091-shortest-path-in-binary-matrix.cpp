class Solution {
public:
    bool isValid(vector<vector<int>>& grid , vector<vector<bool>>&visited , int row , int col)
    {
        if(row<0 || row>=grid.size() || col<0 || col>=grid[0].size() || grid[row][col]!=0 || visited[row][col]==true)
        {
            return false;
        }
        return true;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int res = 0;
        vector<vector<bool>>visited(grid.size(),vector<bool>(grid.size(),false));
        if(grid[0][0] == 0)
        {
            q.push({0, 0});
            visited[0][0] = true;
        }
        while(q.empty()==false)
        {
            int size = q.size();
            res++;
            for(int i=0;i<size;i++)
            {
                auto curr = q.front();
                q.pop();
                
                int row = curr.first;
                int col = curr.second;
                
                if(row==grid.size()-1 && col==grid[0].size()-1)
                {
                    return res;
                }
                
                int dx[] = { +1, -1 , 0 , 0 , -1 , +1 , -1 , +1 };
                int dy[] = { 0 , 0 , -1, +1 , -1 , +1 , +1 , -1 };
                
                for(int ind=0;ind<8;ind++)
                {
                    int x = row + dx[ind];
                    int y = col + dy[ind];

                    if(isValid(grid,visited,x,y)==true)
                    {
                        visited[x][y]=true;
                        q.push({x,y});
                    }
                }
                
            }
        }
        return -1;
    }
};