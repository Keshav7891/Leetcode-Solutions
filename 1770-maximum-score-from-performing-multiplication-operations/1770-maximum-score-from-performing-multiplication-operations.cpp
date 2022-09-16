class Solution {
public:
    vector<vector<int>>dp;
    int help(int low , int high , int index , vector<int>&nums , vector<int>&multipliers)
    {
        if(index==multipliers.size())
        {
            return 0;
        }
        
        if(dp[low][index]!=INT_MIN)
        {
            return dp[low][index];
        }
        
        int left = nums[low] * multipliers[index] + help(low+1,high,index+1,nums,multipliers);
        int right = nums[high] * multipliers[index] + help(low,high-1,index+1,nums,multipliers);
        
        return  dp[low][index] = max(left,right);
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n= nums.size();
        int m= multipliers.size();
        dp.resize(m + 1, vector<int>(m + 1, INT_MIN));
        int res = help(0,nums.size()-1,0,nums,multipliers);
        return res;
    }
};