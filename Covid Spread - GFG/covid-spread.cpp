//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    bool help(int i , int j , vector<vector<int>> &grid)
    {
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]!=1)
        {
            return false;
        }
        return true;
    }
    int helpaterp(vector<vector<int>> grid)
    {
        queue<pair<pair<int,int>,int>>q;
        
        int uneffected = 0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({{i,j},0});
                }
                if(grid[i][j] == 1)
                {
                    uneffected++;
                }   
            }
        }
        int dx[4] = { -1 ,  0  , 1 , 0 };
        int dy[4] = {  0 , -1  , 0 , 1 };
        int res = 0;
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
                res = max(res,steps);
                
                for(int j=0;j<4;j++)
                {
                    int x = row + dx[j];
                    int y = col + dy[j];
                    
                    bool check = help(x,y,grid);
                    if(check == true)
                    {
                        uneffected--;
                        grid[x][y] = 2;
                        q.push({{x,y},steps+1});
                    }
                }
            }
        }
        if(uneffected!=0)
        {
            return -1;
        }
        return res;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R;int C;
        
        cin>>R>>C;
        vector<vector<int>> hospital;
        int i,j;
        for(i=0;i<R;i++)
         {   vector<int> temp;
             for(j=0;j<C;j++)
            {
                int k;
                cin>>k;
                temp.push_back(k);
            }
            hospital.push_back(temp);
         }
        
        Solution ob;
        int ans = ob.helpaterp(hospital);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends