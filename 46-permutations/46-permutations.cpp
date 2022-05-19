class Solution {
public:
    vector<vector<int>>res;
    void help(int index , vector<int>&nums)
    {
        if(index == nums.size())
        {
            res.push_back(nums);
            return ;
        }
        
        for(int j=index;j<nums.size();j++)
        {
            swap(nums[index],nums[j]);
            help(index +1 , nums);
            swap(nums[index],nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        help(0,nums);
        return res;
    }
};