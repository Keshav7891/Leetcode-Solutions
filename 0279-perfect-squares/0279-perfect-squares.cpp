class Solution {
public:
    int help(int target , vector<int>&dp)
    {
        if(target == 0)
        {
            return 0;
        }
        if(dp[target]!=-1)
        {
            return dp[target];
        }
        int res = INT_MAX;
        for(int i=1;i<=sqrt(target);i++)
        {
            int val = i*i;
            if(target-val>=0)
            {
                int op = 1 + help(target-i*i,dp);
                res = min(res,op);
            }
        }
        return dp[target] = res;
    }
    int numSquares(int n) {
        vector<int>dp(n+1,-1);
        return help(n,dp);   
    }
};