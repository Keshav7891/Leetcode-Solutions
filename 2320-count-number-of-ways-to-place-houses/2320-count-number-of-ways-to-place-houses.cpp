class Solution {
public:
    /*
    -   -   -   -   -   -   -
    0   1   2   3   4   5   6
    -   -   -   -   -   -   -
    7   8   9   10  11  12  13
    */
    long long mod = 1000000007;
    long long help(int plot , bool built , vector<vector<int>>&dp)
    {
        if(plot == 1)
        {
            return 1;
        }
        if(dp[plot][built]!=-1)
        {
            return dp[plot][built];
        }
        long long build = 0;
        long long skip = 0;
        if(built == false)
        {
            build = help(plot-1,true,dp);
            skip = help(plot-1,false,dp);
            return dp[plot][built] = (build + skip)%mod;
        }
        else
        {
            skip = help(plot-1,false,dp);
            return dp[plot][built] = skip;
        }
    }
    int countHousePlacements(int n) {
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        long long options = (help(n,false,dp) + help(n,true,dp))%mod;
        return (options * options)%mod;
    }
};