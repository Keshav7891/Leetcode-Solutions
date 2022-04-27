class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                nums[i]=-1;
            }
        }
        unordered_map<int,int>m;
        m[0]=-1;
        int res=0;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum=sum+nums[i];
            if(m.find(sum)!=m.end())
            {
                int len = i-m[sum];
                res=max(res,len);
            }
            else
            {
                m[sum]=i;
            }
        }
        return res;
    }
};