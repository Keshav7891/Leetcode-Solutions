class Solution {
public:
    const int mod = 1e9+7;
    long long int help(int n , int curr , int picked , vector<int>&rollMax , vector<vector<vector<int>>>&dp)
    {
        if(n == 0)
        {
            return 1;
        }
        if(dp[n][curr][picked]!=-1)
        {
            return dp[n][curr][picked];
        }
        long long int res = 0;
        if(picked < rollMax[curr-1])
        {
            res = (res + help(n-1,curr,picked+1,rollMax,dp))%mod;
        }
        for(int i=1;i<=6;i++)
        {
            if(i!=curr)
            {
                res = (res + help(n-1,i,1,rollMax,dp))%mod;
            }
        }
        return dp[n][curr][picked] = res;
    }
    int dieSimulator(int n, vector<int>& rollMax) {
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(6+1,vector<int>(15+1,-1)));
        return (help(n-1,1,1,rollMax,dp) + help(n-1,2,1,rollMax,dp) + help(n-1,3,1,rollMax,dp) + help(n-1,4,1,rollMax,dp) + help(n-1,5,1,rollMax,dp) + help(n-1,6,1,rollMax,dp))%mod;
    }
};