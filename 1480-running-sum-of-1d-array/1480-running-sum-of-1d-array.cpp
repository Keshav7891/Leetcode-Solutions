class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int prefix_sum=0;
        for(int i=0;i<nums.size();i++)
        {
            prefix_sum=prefix_sum+nums[i];
            nums[i]=prefix_sum;
        }
        return nums;
    }
};