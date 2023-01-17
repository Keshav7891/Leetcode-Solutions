class Solution {
public:
    int help(int index , int target , vector<int>&coins , vector<vector<int>>&dp)
    {
        if(index == coins.size()-1)
        {
            if(target % coins[index] == 0)
            {
                return target/coins[index];
            }
            else
            {
                return 1e9;
            }
        }
        if(dp[index][target]!=-1)
        {
            return dp[index][target];
        }
        int op1 = 0 + help(index+1,target,coins,dp);
        int op2 = 1e9;
        if(target-coins[index] >= 0)
            op2 = 1 + help(index,target-coins[index],coins,dp);
        return dp[index][target] = min(op1,op2);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,-1));
        int res = help(0,amount,coins,dp);
        if(res == 1e9)
        {
            return -1;
        }
        return res;
    }
};