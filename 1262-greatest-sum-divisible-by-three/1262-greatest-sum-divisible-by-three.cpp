class Solution {
public:
    int help(int index , int rem , vector<int>&nums ,  vector<vector<int>>&dp)
    {
        if(index == nums.size())
        {
            if(rem % 3 == 0)
            {
                return 0;
            }
            else
            {
                return -10000;
            }
        }
        if(dp[index][rem]!=-1)
        {
            return dp[index][rem];
        }
        int curr = nums[index];
        int op1 = curr + help(index + 1,(rem + curr)%3,nums,dp);
        int op2 = 0 + help(index + 1,rem,nums,dp);
        
        return dp[index][rem] = max(op1,op2);
    }
    int maxSumDivThree(vector<int>& nums) {
        vector<vector<int>>dp(nums.size()+1,vector<int>(3,-1));
        return help(0,0,nums,dp);
    }
};