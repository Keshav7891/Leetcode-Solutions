class Solution {
public:
    int minOperations(vector<int>& nums) 
    {
        int res=nums.size();
        int j=0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        nums.erase(unique(nums.begin(),nums.end()),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            while(j<nums.size() && nums[j]-nums[i]<=n-1)
            {
                j++;
            }
            res=min(res,i+n-j);
        }
        return res;
    }
};