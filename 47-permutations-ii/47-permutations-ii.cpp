class Solution {
public:

    vector<vector<int>>res;
    void help(int index , vector<int>&nums)
    {
        if(index==nums.size()-1)
        {
            res.push_back(nums);
        }
        unordered_set<int>s;
        for(int i=index;i<nums.size();i++)
        {
            if(s.find(nums[i])!=s.end())
            {
                continue;
            }
            s.insert(nums[i]);
            swap(nums[index],nums[i]);
            help(index+1,nums);
            swap(nums[index],nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        help(0,nums);
        return res;
    }
};