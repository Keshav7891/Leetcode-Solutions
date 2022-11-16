//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int dx[4] = { -1 , 1 ,  0 , 0 };
    int dy[4] = {  0 , 0 , -1 , 1 };
    
    bool isValid(int i , int j , vector<vector<bool>>&visited , vector<vector<int>>&grid)
    {
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || visited[i][j]==true || grid[i][j]!=1)
        {
            return false;
        }
        return true;
    }
    
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        queue<pair<pair<int,int>,int>>q;
        q.push({{source.first , source.second},0});
        vector<vector<bool>>visited(grid.size(),vector<bool>(grid[0].size(),false));
        visited[source.first][source.second]=true;
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
                
                if(row == destination.first && col == destination.second)
                {
                    return steps;
                }
                
                for(int j=0;j<4;j++)
                {
                    int x = row + dx[j];
                    int y = col + dy[j];
                    
                    if(isValid(x,y,visited,grid)==true)
                    {
                        visited[x][y] = true;
                        q.push({{x,y},steps+1});
                    }
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends