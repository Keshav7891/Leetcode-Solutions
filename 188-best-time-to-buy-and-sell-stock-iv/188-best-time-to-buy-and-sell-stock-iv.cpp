class Solution {
public:
    int buy_and_sell_II(vector<int>& prices)
    {
        int profit = 0;
        for(int i=1;i<prices.size();i++)
        {
            if(prices[i]>prices[i-1])
            {
                profit = profit + (prices[i]-prices[i-1]);
            }
        }
        return profit;
    }
    int maxProfit(int k, vector<int>& prices)
    {
        if(k>=prices.size()/2)
        {
            return buy_and_sell_II(prices);
        }
        if(k==0)
        {
            return 0;
        }
        int min_price[k],max_price[k];
        for(int i=0;i<k;i++)
        {
            min_price[i]=INT_MAX;
            max_price[i]=0;
        }
        for(int i=0;i<prices.size();i++)
        {
            for(int j=0;j<k;j++)
            {
                min_price[j]=min(min_price[j],prices[i]-(j>0? max_price[j-1]:0 ));
                max_price[j]=max(max_price[j],prices[i]-min_price[j]);
            }
        }
        return max_price[k-1];
        
    }
};