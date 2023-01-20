class Solution {
public:
    const int mod = 1e9+7;
    long long int help(int n, int absentee , int late ,  vector<vector<vector<int>>>&dp)
    {
        if(absentee == 2 || late == 3)
        {
            return 0;
        }
        if(n == 0)
        {
            return 1;
        }
        if(dp[n][absentee][late]!=-1)   return dp[n][absentee][late];
        long long int res = 0;
        res = (res + help(n-1,absentee,0,dp))%mod;
        res = (res + help(n-1,absentee+1,0,dp))%mod;
        res = (res + help(n-1,absentee,late + 1,dp))%mod;
        return dp[n][absentee][late] = res;
    }
    int checkRecord(int n) {
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2+1,vector<int>(3+1,-1)));
        return help(n,0,0,dp);
    }
};