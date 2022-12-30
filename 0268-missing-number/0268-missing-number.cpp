class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = (n*(n+1))/2;
        for(auto key : nums)
        {
            sum = sum - key;
        }
        return sum;
    }
};