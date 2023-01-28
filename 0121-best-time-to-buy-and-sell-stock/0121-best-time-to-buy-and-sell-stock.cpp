class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int res = 0;
        int buy = INT_MAX;
        int sell = INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            buy = min(buy,nums[i]);
            sell = nums[i];
            int profit = sell-buy;
            res = max(res,profit);
        }
        return res;
    }
};