class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        int res = INT_MIN;
        int curr_sum = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(curr_sum>0)
            {
                curr_sum = curr_sum + nums[i];
            }
            else
            {
                curr_sum = nums[i];
            }
            res = max(res,curr_sum);
        }
        return res;
    }
};