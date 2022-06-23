class Solution {
public:
    int help(vector<int>nums)
    {
        vector<int> dp_exclude(nums.size());
        vector<int> dp_include(nums.size());
        
        dp_exclude[0]=0;
        dp_include[0]=nums[0];
        
        
        for(int i=1;i<nums.size();i++)
        {
            dp_include[i]=nums[i]+dp_exclude[i-1];
            dp_exclude[i]=max(dp_include[i-1],dp_exclude[i-1]);
        }
        int res = max(dp_include[nums.size()-1],dp_exclude[nums.size()-1]);
        return res;
    }
    int rob(vector<int>& nums) 
    {
        
        if(nums.size()==1)
        {
            return nums[0];
        }
        
        vector<int> house1(nums.begin() + 1, nums.end());
        vector<int> house2(nums.begin(), nums.end()-1);
        
        int res1 = help(house1);
        int res2 = help(house2);
        cout<<res1<<" "<<res2;
        return max(res1,res2);
        
    }
};