class Solution {
public:
    int minSubarray(vector<int>& nums, int k) {
        long long int sum = 0;
        for(auto key : nums)
        {
            sum = sum + key;
        }
        int target = sum%k;
        if(target==0)
        {
            return 0;
        }
        int res = INT_MAX;
        long long int prefix = 0;
        unordered_map<long long int,int>m;
        m[0]=-1;
        for(int i=0;i<nums.size();i++)
        {
            prefix = prefix + nums[i];
            int req = (prefix-target)%k;
            if(m.find(req)!=m.end())
            {
                res = min(res,i-m[req]);
            }
            m[prefix%k]=i;
        }
        if(res==nums.size())
        {
            return -1;
        }
        else
        {
            return res;
        }
    }
};