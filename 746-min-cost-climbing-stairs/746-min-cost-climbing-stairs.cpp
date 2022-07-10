class Solution {
public:
    int help(int index , vector<int>&cost, vector<int>&dp)
    {
        if(index>=cost.size())
        {
            return 0;
        }
        if(dp[index]!=-1)
        {
            return dp[index];
        }
        int left = help(index+1,cost,dp);
        int right = help(index+2,cost,dp);
        dp[index] = min(left,right)+cost[index];
        return dp[index];
    }
    int minCostClimbingStairs(vector<int>& cost) 
    {
        vector<int>dp(cost.size()+1,-1);
        return min(help(0,cost,dp),help(1,cost,dp));
    }
};