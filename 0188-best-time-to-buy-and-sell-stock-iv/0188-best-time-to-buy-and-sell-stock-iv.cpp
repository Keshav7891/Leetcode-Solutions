class Solution {
public:
    int help(int index , int k , int buy , vector<int>& nums , vector<vector<vector<int>>>&dp)
    {
        if(index==nums.size() || k==0)
        {
            return 0;
        }
        if(dp[index][k][buy]!=-1)
        {
            return dp[index][k][buy];
        }
        int profit = 0;
        if(buy == 1)
        {
            int buy_now = -nums[index] + help(index + 1 , k , 0 , nums , dp);
            int skip_now = 0 + help(index + 1 , k , 1 , nums , dp);
            profit = max(buy_now,skip_now);
        }
        else
        {
            int sell_now = nums[index] + help(index + 1 , k - 1 , 1 , nums , dp);
            int skip_now = 0 + help(index + 1 , k , 0 , nums , dp);
            profit = max(sell_now,skip_now);
        }
        return dp[index][k][buy] = profit;
    }
    int maxProfit(int k , vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size()+1,vector<vector<int>>(k+1,vector<int>(2+1,-1)));
        return help(0,k,1,prices,dp);
    }
};