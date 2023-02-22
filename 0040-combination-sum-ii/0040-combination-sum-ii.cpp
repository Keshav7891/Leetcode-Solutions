class Solution {
public:
    void help(int index,vector<int>& nums, int sum , vector<vector<int>>& res, vector<int>& path)
    {
        if(sum==0)
        {
            res.push_back(path);
            return;
        }
        for(int i=index;i<nums.size();i++)
        {
            if(i>index && nums[i]==nums[i-1])
            {
                continue;
            }
            if(nums[i]>sum)
            {
                break;
            }
            path.push_back(nums[i]);
            help(i+1,nums,sum-nums[i],res,path);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int sum) 
    {
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        vector<int>path;
        help(0,nums,sum,res,path);
        return res;
    }
};