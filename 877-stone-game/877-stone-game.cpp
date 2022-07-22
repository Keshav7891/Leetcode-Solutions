class Solution {
public:
    
    int help(vector<int>nums,int i , int j , vector<vector<int>>&dp)
    {
        if(i>j)
        {
            return 0;
        }
        
        
        
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        
        int pick_first = nums[i] + min(help(nums,i+2,j,dp),help(nums,i+1,j-1,dp));
        int pick_last = nums[j] + min(help(nums,i+1,j-1,dp),help(nums,i,j-2,dp));
        
        return dp[i][j] = max(pick_first,pick_last);
        
    }
    
    bool stoneGame(vector<int>& nums) 
    {
        int sum = 0;
        for(auto key : nums)
        {
            sum = sum + key;
        }
        vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        int alice = help(nums,0,nums.size()-1,dp);
        int bob = sum - alice;
        
        if(alice>bob)
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
};