class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        int start = -1;
        int end = -1;
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(nums[mid]==target)
            {
                start = mid;
                high = mid-1;
            }
            else if(target<nums[mid])
            {
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        low = 0;
        high = nums.size()-1;
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(nums[mid]==target)
            {
                end = mid;
                low = mid+1;
            }
            else if(target<nums[mid])
            {
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        return {start,end};
    }
};