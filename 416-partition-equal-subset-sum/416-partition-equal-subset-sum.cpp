class Solution {
public:
    bool help(int index , int target , vector<int>& nums , vector<vector<int>>&dp)
    {
        if(target==0)
        {
            return true;
        }
        if(index==0)
        {
            if(nums[index]==target)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        if(dp[index][target]!=-1)
        {
            return dp[index][target];
        }
        bool not_pick = help(index-1,target,nums,dp);
        bool pick = false;
        if(nums[index]<=target)
        {
            pick = help(index-1,target-nums[index],nums,dp);
        }
        
        bool res = pick || not_pick;
        return dp[index][target] = res;
        
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto key : nums)
        {
            sum = sum + key;
        }
        if(sum%2!=0)
        {
            return false;
        }
        int target = sum/2;
        vector<vector<int>>dp(nums.size(),vector<int>(target+1,-1));
        bool res = help(nums.size()-1,target,nums,dp);
        return res;
    }
};