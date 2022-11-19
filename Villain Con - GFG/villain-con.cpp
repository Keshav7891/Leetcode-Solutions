//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minColour(int N, int M, vector<int> mat[]) {
        vector<int>indegree(N+1,0);
        unordered_map<int,list<int>>adj;
        
        for(int i=0;i<M;i++)
        {
            int u = mat[i][0];
            int v = mat[i][1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int>q;
        for(int i=1;i<indegree.size();i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        int res = 0;
        while(q.empty()==false)
        {
            int size = q.size();
            for(int i = 0; i< size; i++)
            {
                auto curr = q.front();
                q.pop();
                
                for(auto nbr : adj[curr])
                {
                    indegree[nbr]--;
                    if(indegree[nbr]==0)
                    {
                        //cout<<nbr<<endl;
                        q.push(nbr);
                    }
                }
            }
            res++;
        }
        
        return res;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, M, x, y;
        cin>>N>>M;
        vector<int> mat[M];
        for(int i = 0;i < M;i++){
            cin>>x>>y;
            mat[i].push_back(x);
            mat[i].push_back(y);
        }
        
        Solution ob;
        cout<<ob.minColour(N, M, mat)<<"\n";
    }
    return 0;
}
// } Driver Code Ends