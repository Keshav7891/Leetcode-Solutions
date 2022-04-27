class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        unordered_map<int,int>m;
        int sum=0;
        int res=0;
        //m[0]=1;
        for(int i=0;i<nums.size();i++)
        {
            sum=sum+nums[i];
            if(sum==k)
            {
                res++;
            }
            if(m.find(sum-k)!=m.end())
            {
                res=res+m[sum-k];
            }
           
                m[sum]++;
            
        }
        return res;
        
    }
};