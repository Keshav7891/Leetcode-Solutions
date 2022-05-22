class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        vector<int>dp(nums.size());
        dp[0]=1;
        for(int i=1;i<nums.size();i++)
        {
            int element = nums[i];
            int max_len=0;
            for(int j=0;j<i;j++)
            {
                if(element>nums[j])
                {
                    max_len=max(max_len,dp[j]);   
                }
            }
            dp[i]=max_len+1;
        }
        int res=INT_MIN;
        for(auto key : dp)
        {
            res=max(res,key);
        }
        return res;
    }
};