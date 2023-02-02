class Solution {
public:
    // 0 1 2 3 4 5 6 4 3
    // 0 1 2 3 4 5 6 7 8
    int peakIndexInMountainArray(vector<int>& nums) {
        int low = 1;
        int high = nums.size()-2;
        
        while(low <= high)
        {
            int mid = (low + high)/2;
            
            
            if(nums[mid-1] < nums[mid] && nums[mid] > nums[mid+1])
            {
                return mid;
            }
            else if(nums[mid-1] < nums[mid] && nums[mid] < nums[mid+1])
            {
                low = mid + 1;
            }
            else if(nums[mid-1] > nums[mid] && nums[mid] > nums[mid+1])
            {
                high = mid - 1;
            }
        }
        
        return -1;
    }
};