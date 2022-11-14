//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    // 0 1 1 0
    // 1 1 0 0
    // 0 0 1 1
    //Function to find distance of nearest 1 in the grid for each cell.
    bool help(int i , int j , vector<vector<int>>&grid , vector<vector<bool>>&visited)
    {
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || visited[i][j]==true || grid[i][j]==1)
        {
            return false;
        }
        return true;
    }
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    vector<vector<bool>>visited(grid.size(),vector<bool>(grid[0].size(),false));
	    queue<pair<pair<int,int>,int>>q;
	    for(int i=0;i<grid.size();i++)
	    {
	        for(int j=0;j<grid[0].size();j++)
	        {
	            if(grid[i][j]==1)
	            {
	                q.push({{i,j},0});
	                grid[i][j]=0;
	                visited[i][j]=true;
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
	            
	            int row = curr.first.first;
	            int col = curr.first.second;
	            int steps = curr.second;
	            
	            if(grid[row][col]==0)
	            {
	                grid[row][col] = steps;
	            }
	            
	            int dx[4] = { 1, 0 , -1 , 0 };
                int dy[4] = { 0 , 1 , 0 ,-1};
	            
	            for(int j=0;j<4;j++)
	            {
	                int x = row + dx[j];
	                int y = col + dy[j];
	                
	                bool check = help(x,y,grid,visited);
	                if(check == true)
	                {
	                    visited[x][y] = true;
	                    q.push({{x,y},steps+1});
	                }
	            }
	        }
	    }
	    return grid;
	    // Code here
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends