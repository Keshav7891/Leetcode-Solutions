//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minThrow(int N, int arr[]){
        unordered_map<int,int>adj;
        for(int i=0;i<2*N;i=i+2)
        {
            int start = arr[i];
            int end = arr[i+1];
            adj[start] = end;
        }
        int pos = 1;
        vector<bool>visited(31,false);
        visited[1]=true;
        queue<pair<int,int>>q;
        q.push({pos,0});
        while(q.empty()==false)
        {
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                auto curr = q.front();
                q.pop();
                
                int position = curr.first;
                int steps = curr.second;
                
                if(position == 30)
                {
                    return steps;
                }
                
                for(int i=1;i<=6;i++)
                {
                    int nextPosition = position + i;
                    if(adj.find(nextPosition)!=adj.end())
                    {
                        if(nextPosition<=30)
                        {
                            nextPosition = adj[nextPosition];
                            q.push({nextPosition,steps+1});   
                        }
                    }
                    else
                    {
                        if(nextPosition<=30)
                        {
                            q.push({nextPosition,steps+1});
                        }
                    }
                }
            }
        }
        return -1;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends