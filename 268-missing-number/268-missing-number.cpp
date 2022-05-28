class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        int sum = (nums.size()*(nums.size()+1))/2;
        for(auto key : nums)
        {
            sum=sum-key;
        }
        return sum;
    }
};