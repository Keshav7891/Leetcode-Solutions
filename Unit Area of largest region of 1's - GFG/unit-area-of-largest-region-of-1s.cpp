//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    void dfs(int i , int j , vector<vector<int>>& grid , int &area)
    {
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]!=1)
        {
            return;
        }
        area++;
        grid[i][j] = -1;
        dfs(i-1,j,grid,area);
        dfs(i-1,j+1,grid,area);
        dfs(i,j+1,grid,area);
        dfs(i+1,j+1,grid,area);
        dfs(i+1,j,grid,area);
        dfs(i+1,j-1,grid,area);
        dfs(i,j-1,grid,area);
        dfs(i-1,j-1,grid,area);
    }
    int findMaxArea(vector<vector<int>>& grid) {
        
        int res = 0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    int area = 0;
                    dfs(i,j,grid,area);
                    res = max(res,area);
                }
            }
        }
        return res;
        
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
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends