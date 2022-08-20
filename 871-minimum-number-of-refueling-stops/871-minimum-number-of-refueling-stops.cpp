class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
        priority_queue<int>pq;
        int travel = startFuel;
        int index = 0;
        int res = 0;
        while(travel<target)
        {
    
            while(index < stations.size() && stations[index][0] <= travel )
            {
                pq.push(stations[index][1]);
                index++;
            }
            
            if(pq.empty()==true)
            {
                return -1;
            }
            travel = travel + pq.top();
            pq.pop();
            res++;
        }
        
        return res;
        
        
    }
};