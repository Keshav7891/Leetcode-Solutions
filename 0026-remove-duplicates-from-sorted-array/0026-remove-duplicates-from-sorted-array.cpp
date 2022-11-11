class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int no=1;
        if(nums.empty())
        {
            return 0;
        }
        else 
        {
            for(int i=0;i<nums.size();i++)
            {
                if(nums[i]!=nums[no-1])
                {
                    nums[no]=nums[i];
                    no++;
                }
            }
        }
        return no;
    }
};