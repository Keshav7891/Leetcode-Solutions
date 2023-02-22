class Solution {
public:
    vector<vector<int>>res;
    void help(int index , int &pathSum , vector<int>&path , vector<int>&nums , int target)
    {
        if(pathSum > target)    return;
        if(index == nums.size())
        {
            if(pathSum == target)
            {
                res.push_back(path);
            }
            return;
        }
        
        path.push_back(nums[index]);
        pathSum = pathSum + nums[index];
        help(index,pathSum,path,nums,target);
        path.pop_back();
        pathSum = pathSum - nums[index];
        help(index+1,pathSum,path,nums,target);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>path;
        int pathSum = 0;
        help(0,pathSum,path,nums,target);
        return res;
    }
};