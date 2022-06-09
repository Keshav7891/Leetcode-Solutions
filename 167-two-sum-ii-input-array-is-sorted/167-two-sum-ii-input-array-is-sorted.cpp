class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        int start=0,end=nums.size()-1;
        vector<int>res;
        int sum;
        while(start<end)
        {
            int sum=nums[start]+nums[end];
            if(sum==target)
            {
                res.push_back(start+1);
                res.push_back(end+1);
                break;
            }
            else if(sum<target)
            {
                start=start+1;
            }
            else if(sum>target)
            {
                end=end-1;
            }
        }
        return res;
        
    }
};