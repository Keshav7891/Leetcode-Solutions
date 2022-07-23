class Solution {
public:
    int dp[100001][2][3];
    int help(int i , int buy , int k , vector<int>&nums)
    {
        if(i==nums.size() || k==0)
        {
            return 0;
        }
        if(dp[i][buy][k]!=-1)
        {
            return dp[i][buy][k];
        }
        int profit = 0;
        if(buy==0)
        {
            int buy_now = -nums[i] + help(i+1,1,k,nums);
            int skip = 0 + help(i+1,0,k,nums);
            profit = max(buy_now,skip);
        }
        else
        {
            int sell_now = +nums[i] + help(i+1,0,k-1,nums);
            int skip = 0 + help(i+1,1,k,nums);
            profit = max(sell_now,skip);
        }
        return dp[i][buy][k] = profit;
    }
    int maxProfit(vector<int>& nums)
    {
        memset(dp, -1, sizeof(dp));
        int res = help(0,0,2,nums);
        return res;
        
    }
};