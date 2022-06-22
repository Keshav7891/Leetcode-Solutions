class Solution {
public:
    int maxChunksToSorted(vector<int>& nums) 
    {
        int n = nums.size();
        
        //computig left max
        vector<int>left_max(n);
        left_max[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            left_max[i] = max(left_max[i-1],nums[i]);
        }
        
        //computing right min
        vector<int>right_min(n);
        right_min[n-1]=nums[n-1];
        for(int i=nums.size()-2;i>=0;i--)
        {
            right_min[i] = min(right_min[i+1],nums[i]);
        }
        
        //left max defines impact of element
        //right min defines if the element comes under impact
        
        int count = 1;
        for(int i=0;i<n-1;i++)
        {
            if(left_max[i]<=right_min[i+1])    //if element is not in impact we need a partition
            {
                count++;
            }
        }
        return count;
        
    }
};