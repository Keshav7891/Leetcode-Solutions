class Solution {
public:
    int help(int target , vector<int>&nums , vector<int>&dp)
    {
        if(target == 0)
        {
            return 1;
        }
        if(dp[target]!=-1)
        {
            return dp[target];
        }
        int op = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(target-nums[i]>=0)
            {
                op = op + help(target - nums[i],nums,dp);
            }
        }
        return dp[target] = op;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>dp(target+1,-1);
        return help(target,nums,dp);
    }
};