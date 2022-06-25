class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        int mid;
        int left = 0;
        int right = nums.size()-1;
        while(left<right)
        {
            mid = left + (right-left)/2;
            if(nums[mid]>nums[right])
            {
                left = mid +1;
            }
            else if(nums[mid]<nums[right])
            {
                right = mid;
            }
            else 
            {
                return nums[right];
            }
        }
        return nums[left];
        
    }
};