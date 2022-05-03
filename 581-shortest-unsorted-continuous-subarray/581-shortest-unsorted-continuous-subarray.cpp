class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) 
    {
        int small = INT_MAX;
        int large = INT_MIN;
        int n=nums.size();
        if(n==1)
        {
            return 0;
        }
        for(int i=0;i<n;i++)
        {
            if(i==0)//If we are at first element 
            {
                if(nums[i]>nums[i+1])
                {
                    small=min(small,nums[i]);
                    large=max(large,nums[i]);
                }
            }
             else if(i==n-1)//if we are at last element
            {
                if(nums[i-1]>nums[i])
                {
                    small=min(small,nums[i]);
                    large=max(large,nums[i]);
                }
            }
            else
            {
                if(nums[i]>nums[i+1] || nums[i]<nums[i-1])//if we are at middle element
                {
                    small=min(small,nums[i]);
                    large=max(large,nums[i]);
                }
            }
            
        }
        if(small==INT_MAX || large==INT_MIN)
        {
            return 0;
        }
        int i,j;
        for(i=0;i<n && nums[i]<=small;i++);
        for(j=n-1;j>0 && nums[j]>=large;j--);
        return j-i+1;

    }
    
};