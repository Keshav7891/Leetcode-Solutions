class Solution {
public:
    int help(int index , int target , vector<int>&coins , vector<vector<int>>&dp)
    {
        if(index == coins.size()-1)
        {
            if(target%coins[index]==0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        if(dp[index][target]!=-1)
        {
            return dp[index][target];
        }
        int op1 = help(index+1,target,coins,dp);
        int op2 = 0;
        if(target-coins[index] >= 0)
            op2 = help(index,target-coins[index],coins,dp);
        return dp[index][target] = op1 + op2;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,-1));
        return help(0,amount,coins,dp);
    }
};