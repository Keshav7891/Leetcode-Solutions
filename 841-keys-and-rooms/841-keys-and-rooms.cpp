class Solution 
{
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms)
    {
        
        unordered_map<int,vector<int>>adj;
        unordered_map<int,bool>visited;
        int i=0;
        for(auto key : rooms)
        {
            adj[i]=key;
            i++;
        }
        
        int count=0;
        queue<int>q;
        q.push(0);
        visited[0]=true;
        
        while(q.empty()==false)
        {
            auto curr = q.front();
            q.pop();
            count++;
            
            for(auto nbr : adj[curr])
            {
                if(visited[nbr]==false)
                {
                    q.push(nbr);
                    visited[nbr]=true;
                }
            }
        }
        
        if(count == rooms.size())
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
};