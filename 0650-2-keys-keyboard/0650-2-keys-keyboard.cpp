class Solution {
public:
    int help(int len , int copied , int target , vector<vector<int>>&dp)
    {
        if(len == target)
        {
            return 0;
        }
        else if(len > target)
        {
            return 1001;
        }
        if(dp[len][copied]!=-1)
        {
            return dp[len][copied];
        }
        
        int copy_paste = 2 + help(len + len , len , target , dp);
        int paste =  1 + help(len + copied , copied , target , dp);
        
        return dp[len][copied] = min({copy_paste , paste});
    }
    int minSteps(int n) 
    {
        vector<vector<int>>dp(n+1,vector<int>(1000+1,-1));
        if(n==0 || n==1)
        {
            return 0;
        }
        return 1 + help(1,1,n,dp);
        
    }
};