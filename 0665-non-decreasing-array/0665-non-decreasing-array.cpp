class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        for(int i=nums.size()-2;i>=0;i--)
        {
            if(nums[i+1]<nums[i])
            {
                if(i!=0 && nums[i-1]>nums[i+1])
                {
                    nums[i+1] = nums[i];
                    break;
                }
                else
                {
                    nums[i] = nums[i+1];
                    break;
                }
            }
        }
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i+1]<nums[i])
            {
                return false;
            }
        }
        return true;
    }
};