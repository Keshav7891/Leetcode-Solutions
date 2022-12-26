class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        vector<bool>dp(nums.size());
        dp[nums.size()-1]=true;
        for(int i=nums.size()-2;i>=0;i--)
        {
            int check = false;
            for(int j=1;j<=nums[i];j++)
            {
                if(i+j<nums.size())
                {
                    if(dp[i+j]==true)
                    {
                        check=true;
                        break;
                    }
                }
            }
            dp[i]=check;
        }
        return dp[0];
        
    }
};