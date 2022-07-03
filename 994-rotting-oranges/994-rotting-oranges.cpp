class Solution {
public:
    bool isValid(vector<vector<int>>& grid , int row , int col)
    {
        if(row<0 || row>=grid.size() || col<0 || col>=grid[0].size() || grid[row][col]!=1)
        {
            return false;
        }
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int chk = 0;
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({make_pair(i,j),0});
                }
                if(grid[i][j]!=0)
                {
                    chk++;
                }
            }
        }
        int time = 0;
        int rotten = 0;
        while(q.empty()==false)
        {
            auto curr = q.front();
            q.pop();
            auto node = curr.first;
            int count = curr.second;
            
            time = max(time,count);
            rotten++;
            
            int row = node.first;
            int col = node.second;
            
            int dx[4] = {0,1,0,-1};
            int dy[4] = {1,0,-1,0};
            
            for(int ind = 0 ; ind<4 ; ind++)
            {
                int x = row + dx[ind];
                int y = col + dy[ind];
                
                if(isValid(grid,x,y)==true)
                {
                    grid[x][y]=2;
                    q.push({{x,y},count+1});
                }
            }
        }
        if(rotten == chk)
        {
            return time;
        }
        else
        {
            return -1;
        }
    }
};