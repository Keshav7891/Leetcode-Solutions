class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        int high = nums.size()-1;
        int low = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=0)
            {
                swap(nums[low],nums[i]);
                low++;
            }
        }
    }
};