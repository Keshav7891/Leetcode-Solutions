class Solution {
public:
    int partitionDisjoint(vector<int>& nums)
    {
        vector<int>left_max(nums.size());
        left_max[0]=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            left_max[i]=max(left_max[i-1],nums[i]);
        }
        vector<int>right_min(nums.size());
        right_min[nums.size()-1]=nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--)
        {
            right_min[i]=min(right_min[i+1],nums[i]);
        }
        int pos;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(left_max[i]<=right_min[i+1])
            {
                pos = i;
                break;
            }
        }
        return pos+1;
        
    }
};