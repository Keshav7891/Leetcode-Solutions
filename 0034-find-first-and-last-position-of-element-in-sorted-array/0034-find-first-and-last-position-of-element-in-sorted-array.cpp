class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first_pos = -1, last_pos = -1;
        int low = 0;
        int high = nums.size()-1;
        while(low<=high)
        {
            int mid = (low + high)/2;
            if(nums[mid] == target)
            {
                first_pos = mid;
                high = mid - 1;
            }
            else if(nums[mid] > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        
        low = 0;
        high = nums.size()-1;
        while(low<=high)
        {
            int mid = (low + high)/2;
            if(nums[mid] == target)
            {
                last_pos = mid;
                low = mid + 1;
            }
            else if(nums[mid] > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return {first_pos,last_pos};
    }
};