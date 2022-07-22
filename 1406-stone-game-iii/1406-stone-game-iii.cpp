class Solution {
public:
    int help(vector<int> &nums,int i,vector<int>&dp){
        if(i>=nums.size()) return 0;
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        int ans=nums[i]-help(nums,i+1,dp);
        if(i+1<nums.size()) ans=max(ans,nums[i]+nums[i+1]-help(nums,i+2,dp));
        if(i+2<nums.size()) ans=max(ans,nums[i]+nums[i+1]+nums[i+2]-help(nums,i+3,dp));
        return dp[i] = ans;
    }
    string stoneGameIII(vector<int>& nums)
    {
        vector<int>dp(nums.size()+1,-1);
        int alice=help(nums,0,dp);
        if(alice>0) return "Alice";
        else if(alice<0) return "Bob";
        else return "Tie";
    }
};