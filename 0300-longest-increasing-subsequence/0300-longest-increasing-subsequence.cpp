class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>dp(nums.size()+1,1);
        int res = 1;
        for(int i=0;i<nums.size();i++)
        {
            int curr = nums[i];
            int len = 1;
            for(int j=0;j<nums.size();j++)
            {
                if(curr > nums[j])
                {
                    len = max(len,dp[j]);
                }
            }
            dp[i] = len+1;
            res = max(res,len);
        }
        return res;
    }
};