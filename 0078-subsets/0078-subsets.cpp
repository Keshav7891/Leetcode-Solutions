class Solution {
public:
     vector<vector<int>>res;
    void help(int index , vector<int>&path,vector<int>&nums)
    {
        if(index == nums.size())
        {
            res.push_back(path);
            return ;
        }
        
        path.push_back(nums[index]);
        help(index+1,path,nums);
        path.pop_back();
        help(index+1,path,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>path;
        help(0,path,nums);
        return res;
    }
};