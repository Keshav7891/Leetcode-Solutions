class Solution {
public:
    double help(int index , int k , vector<int>& nums , vector<vector<double>>&dp)
    {
        if(index == nums.size())
        {
            if(k==0)
            {
                return 0.0;
            }
        }
        if(k==0)
        {
            return INT_MIN;
        }
        if(dp[index][k]!=-1)
        {
            return dp[index][k];
        }
        double res = 0;
        double op = 0;
        double curr_sum = 0;
        for(int i=index;i<nums.size();i++)
        {
            curr_sum = curr_sum + nums[i];
            double avg = curr_sum / (i-index+1) * 1.0;
            op = avg + help(i+1,k-1,nums,dp);
            res = max(res,op);
        }
        return dp[index][k] = res;
    }
    double largestSumOfAverages(vector<int>& nums, int k) {
        vector<vector<double>>dp(nums.size()+1,vector<double>(k+1,-1));
        return help(0,k,nums,dp);
    }
};