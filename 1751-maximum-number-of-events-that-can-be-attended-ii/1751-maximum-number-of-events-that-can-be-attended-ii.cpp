class Solution {
public:
    /*
    ( 33 33 33 33 33 57 )
    ( 33 33 38 38 38 42 ) 
    ( 33 33 38 38 80 ) 
    ( 33 33 42 57 57 ) 
    ( 33 37 38 38 38 38 ) 
    ( 33 37 38 57 57 ) 
    ( 37 37 37 37 37 37 ) 
    ( 38 42 42 100 ) 
    ( 42 80 100 ) - > 0 , 2 , 3
    */
    int help(int index , int k , vector<vector<int>>& events, vector<vector<int>>&dp)
    {
        if(index == events.size() || k==0)
        {
            return 0;
        }
        if(dp[index][k]!=-1)
        {
            return dp[index][k];
        }
        
        int s = events[index][0] , e = events[index][1] , val = events[index][2];
        int i = index+1;
        int low = index+1, high = events.size() - 1;
        while(low <= high){
            int mid = low+(high-low)/2;

            if(events[mid][0] > events[index][1])
            {
                high = mid - 1;
            }
            else 
            {
                low = mid+1;
            }
        }
        
        int op1 = 0 + help(index+1,k,events,dp);
        int op2 = val + help(low,k-1,events,dp);
        
        return dp[index][k] = max(op1,op2);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        vector<vector<int>>dp(events.size(),vector<int>(k+1,-1));
        sort(events.begin(),events.end());
        return help(0,k,events,dp);
    }
};