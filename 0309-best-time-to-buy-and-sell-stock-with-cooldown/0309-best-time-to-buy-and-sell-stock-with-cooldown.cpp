class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        vector<int>nums;
        nums.push_back(0);
        for(auto key : prices)
        {
            nums.push_back(key);
        }
        
        vector<int>dp_buy(prices.size()+1);
        vector<int>dp_sell(prices.size()+1);
        vector<int>dp_cool(prices.size()+1);
        
        dp_buy[1]=-nums[1];
        dp_sell[1]=0;
        dp_cool[1]=0;
        
        for(int i=2;i<prices.size()+1;i++)
        {
            dp_buy[i]=max(dp_cool[i-1]-nums[i],dp_buy[i-1]);
            dp_sell[i]=max(nums[i]+dp_buy[i-1],dp_sell[i-1]);
            dp_cool[i]=max(dp_sell[i-1],dp_cool[i-1]);
        }
        
        
        return dp_sell[prices.size()];
        
    }
};