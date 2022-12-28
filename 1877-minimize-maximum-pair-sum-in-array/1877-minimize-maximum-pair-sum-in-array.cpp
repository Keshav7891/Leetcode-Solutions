class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int res = nums[0]+nums[nums.size()-1];
        int low = 1;
        int high = nums.size()-2;
        while(low<high)
        {
            int sum = nums[low] + nums[high];
            res = max(res,sum);
            low++;
            high--;
        }
        return res;
    }
};