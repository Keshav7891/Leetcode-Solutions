class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) 
    {
        if(nums.size()==1)
        {
            return nums[0];
        }
        if(nums[0]!=nums[1])
        {
            return nums[0];
        }
        if(nums[nums.size()-1]!=nums[nums.size()-2])
        {
            return nums[nums.size()-1];
        }
        int low = 0;
        int high = nums.size()-1;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1])
            {
                return nums[mid];
            }
            else if(nums[mid]==nums[mid-1])
            {
                int left = mid-low+1;
                if(left%2!=0)
                {
                    high=mid-2;
                }
                else
                {
                    low=mid+1;
                }
            }
            else if(nums[mid]==nums[mid+1])
            {
                int right = high-mid+1;
                if(right%2!=0)
                {
                    low=mid+2;
                }
                else
                {
                    high=mid-1;
                }
            }
        }
        return -1;
        
    }
};