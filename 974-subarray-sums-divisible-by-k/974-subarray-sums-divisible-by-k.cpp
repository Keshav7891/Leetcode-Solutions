class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) 
    {
        unordered_map<int,int>m;
        int rem = 0;
        int res = 0;
        int prefix_sum = 0;
        m[rem]=1;
        for(int i=0;i<nums.size();i++)
        {
            prefix_sum=prefix_sum + nums[i];
            rem = prefix_sum % k;
            if(rem<0)
            {
                rem = rem + k;
            }
            if(m.find(rem)!=m.end())
            {
                res = res + m[rem];
                m[rem]++;
            }
            else
            {
                m[rem]++;
            }
        }
        return res;
        
    }
};