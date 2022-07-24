class Solution {
public:
    
    int help(vector<int>&nums , int i , int j , vector<vector<int>>&dp)
    {
        if(i>j)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int maxe = INT_MIN;
        for(int ind = i;ind<=j;ind++)
        {
            int cost = nums[i-1]*nums[ind]*nums[j+1] + help(nums,i,ind-1,dp) + help(nums,ind+1,j,dp);
            maxe = max(maxe,cost);
        }
        return dp[i][j] = maxe;
    }
    
    int maxCoins(vector<int>& burst) 
    {
        vector<int>nums;
        nums.push_back(1);
        for(auto key : burst)
        {
            nums.push_back(key);
        }
        nums.push_back(1);
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size(),-1));
        int res = help(nums,1,burst.size(),dp);
        return res;
    }
};