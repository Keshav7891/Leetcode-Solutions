//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class DSU
{
    private :
        vector<int>parent;
        vector<int>size;
    public :
        DSU(int n)
        {
            parent.resize(n+1);
            size.resize(n+1,1);
            for(int i=0;i<=n;i++)
            {
                parent[i] = i;
            }
        }
        
        int findParent(int node)
        {
            if(node == parent[node])
            {
                return node;
            }
            return parent[node] = findParent(parent[node]);
        }
        
        void unionBySize(int u , int v)
        {
            int pu = findParent(u);
            int pv = findParent(v);
            
            if(pu == pv)
            {
                return ;
            }
            
            if(size[pu] < size[pv])
            {
                parent[pu] = pv;
                size[pv] = size[pv] + size[pu];
            }
            else
            {
                parent[pv] = pu;
                size[pu] = size[pu] + size[pv];
            }
        }
};
class Solution {
  public:
    bool help(int x , int y , int n , int m)
    {
        if(x<0 || x>=n || y<0 || y>=m)
        {
            return false;
        }
        return true;
    }
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        vector<vector<bool>>visited(n+1,vector<bool>(m+1,false));
        DSU dsu(n*m);
        int dx[4] = { -1 , 0 , 1 , 0};
        int dy[4] = {  0  , 1 , 0 , -1};
        vector<int>res;
        int count = 0;
        for(auto key : operators)
        {
            int x = key[0];
            int y = key[1];
            
            if(visited[x][y] == true)
            {
                res.push_back(count);
                continue;
            }
            
            visited[x][y] = true;
            count++;
            for(int index=0;index<4;index++)
            {
                int row = x + dx[index];
                int col = y + dy[index];
                
                bool check = help(row,col,n,m);
                if(check == true)
                {
                    if(visited[row][col] == true)
                    {
                        int u = x * m + y;
                        int v = row * m + col;
                        if(dsu.findParent(u) != dsu.findParent(v))
                        {
                            count--;
                            dsu.unionBySize(u,v);
                        }   
                    }
                }
            }
            res.push_back(count);
        }
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends