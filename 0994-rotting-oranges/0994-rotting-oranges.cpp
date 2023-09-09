class Solution {
public:
    bool check(int i , int j , vector<vector<int>>& grid){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]!=1){
            return false;
        }
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int freshCount = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }else if(grid[i][j] == 1){
                    freshCount++;
                }else{
                    grid[i][j] = -1;
                }
            }
        }
        if(freshCount == 0){
            return 0;
        }
        vector<vector<bool>>visited(grid.size(),vector<bool>(grid[0].size(),false));
        int rotted = 0;
        int time = 0;
        while(q.empty()==false){
            int size = q.size();
            for(int i=0;i<size;i++){
                auto curr = q.front();
                q.pop();
                
                int x = curr.first;
                int y = curr.second;
                
                int dx[] = {-1 , 1 ,  0 , 0};
                int dy[] = { 0 , 0 , -1 , 1};
                
                for(int k=0;k<4;k++){
                    int a = x + dx[k];
                    int b = y + dy[k];
                    
                    if(check(a,b,grid) == true){
                        rotted++;
                        grid[a][b] = 2;
                        q.push({a,b});
                    }
                }
            }
            time++;
        }
        if(rotted == freshCount){
            return time-1;
        }
        return -1;
    }
};