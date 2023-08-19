class Solution {
public:
    vector<vector<int>>res;
    void help(int index , int target , vector<int>&nums , vector<int>&path){
        if(index == nums.size()){
            if(target==0){
                res.push_back(path);
                return;
            }
            else{
                return;
            }
        }
        
        if(target-nums[index]>=0){
            path.push_back(nums[index]);
            help(index,target-nums[index],nums,path);
            path.pop_back();
        }
        
        help(index+1,target-0,nums,path);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>path;
        help(0,target,nums,path);
        return res;
    }
};