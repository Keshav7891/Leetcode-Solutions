class Solution {
public:
    int help(int index , vector<int>&nums , vector<int>&dp)
    {
        if(index == 0)
        {
            return nums[0];
        }
        if(index<0)
        {
            return 0;
        }
        if(dp[index]!=-1)
        {
            return dp[index];
        }
        int pick = nums[index] + help(index-2 , nums , dp);
        int not_pick = 0 + help(index-1 , nums , dp);
        return dp[index] = max(pick , not_pick);
    } 
    int rob(vector<int>& nums) 
    {
        vector<int>dp(nums.size()+1,-1);
        int res = help(nums.size()-1 , nums , dp);
        return res;
    }
};