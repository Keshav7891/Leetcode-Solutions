class Solution {
public:
    int cost = 0;
    int help(int index , int buy , vector<int>& nums , vector<vector<int>>&dp)
    {
        if(index>=nums.size())
        {
            return 0;
        }
        if(dp[index][buy]!=-1)
        {
            return dp[index][buy];
        }
        int profit = 0;
        if(buy == 1)
        {
            int buy_now = -nums[index] + help(index + 1, 0 , nums , dp);
            int skip_now = 0 + help(index + 1, 1 , nums , dp);
            profit = max(buy_now,skip_now);
        }
        else
        {
            int sell_now = nums[index] - cost + help(index + 1 , 1 , nums , dp);
            int skip_now = 0 + help(index + 1 , 0 , nums , dp);
            profit = max(sell_now,skip_now);
        }
        return dp[index][buy] = profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        cost = fee;
        vector<vector<int>>dp(prices.size()+1,vector<int>(2+1,-1));
        return help(0,1,prices,dp);
    }
};