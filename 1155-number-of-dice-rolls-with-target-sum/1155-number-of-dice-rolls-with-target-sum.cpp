class Solution {
public:
    const int mod = 1e9 + 7;
    int help(int target , int k , int n , vector<vector<int>>&dp)
    {
        if(n==0 && target==0)
        {
            return 1;
        }
        if(n==0 && target!=0)
        {
            return 0;
        }
        if(dp[target][n]!=-1)
        {
            return dp[target][n];
        }
        int path = 0;
        for(int i=1;i<=k;i++)
        {
            if(target-i>=0 && k>0)
            {
                path = (path + help(target-i,k,n-1,dp))%mod;
            }
        }
        return dp[target][n] = path;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(target+1,vector<int>(n+1,-1));
        int res = help(target,k,n,dp);
        return res;
    }
};