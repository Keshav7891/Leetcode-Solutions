class Solution {
public:
    void sortColors(vector<int>& nums)
    {
        //Three pointers low to point 0 mid to point 1 high to point 2
        int low,mid,high;
        low=mid=0;
        high=nums.size()-1;
        while(mid<=high)
        {
            //if element is 0 swap with 0 pointer
            if(nums[mid]==0)
            {
                swap(nums[low],nums[mid]);
                mid++;
                low++;
            }
            //if element is 1 just move to next element 
            else if(nums[mid]==1)
            {
                mid++;
            }
            //if element is 2 swap with 2 pointer and decrease high
            else if(nums[mid]==2)
            {
                swap(nums[mid],nums[high]);
                high--;
            }
        }
        
    }
};