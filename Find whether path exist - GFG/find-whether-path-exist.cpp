//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    
    bool check(int i , int j , vector<vector<int>> & grid)
    {
        if( i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j] == -1 || grid[i][j] == 0)
        {
            return false;
        }
        return true;
    }
    //Function to find whether a path exists from the source to destination.
    
    bool is_Possible(vector<vector<int>>& grid) 
    {
        queue<pair<int,int>>q;
        int resx;
        int resy;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j] == 1)
                {
                    q.push({i,j});
                    grid[i][j] = -1;
                }
                if(grid[i][j] == 2)
                {
                    //cout<<i<<" "<<j<<endl;
                    resx = i;
                    resy = j;
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
                
                int x = curr.first;
                int y = curr.second;
                
                if(x == resx && y == resy)
                {
                    //cout<<x<<" "<<y<<endl;
                    return true;
                }
                
                int dx[4] = { -1 , 1 , 0 , 0};
                int dy[4] = { 0 , 0 , -1 , 1};
                
                for(int i=0;i<4;i++)
                {
                    int row = x + dx[i];
                    int col = y + dy[i];
                    
                    if(check(row,col,grid) == true)
                    {
                        grid[row][col] = -1;
                        q.push({row,col});
                    }
                }
            }
        }
        
        return false;
        //code here
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}
// } Driver Code Ends