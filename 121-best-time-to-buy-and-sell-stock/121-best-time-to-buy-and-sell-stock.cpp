class Solution {
public:
    int maxProfit(vector<int>& nums) 
    {
        int buy = INT_MAX;
        int sell = INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            buy = min(buy,nums[i]);
            sell = max(sell , nums[i]-buy);
        }
        return sell;
        
    }
};