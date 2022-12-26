class Solution {
public:
    int maxArea(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        int res = 0;
        while(low < high)
        {
            int len = high - low;
            int ht = min(nums[low],nums[high]);
            int ar = len * ht;
            res = max(res,ar);
            if(nums[low] < nums[high])
            {
                low++;
            }
            else
            {
                high--;
            }
        }
        return res;
    }
};