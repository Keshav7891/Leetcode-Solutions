class Solution {
public:
    vector<int> findOriginalArray(vector<int>& nums) 
    {
        if(nums.size()%2!=0)
        {
            return {};
        }
        sort(nums.begin(),nums.end());
        unordered_map<int,int>m;
        for(auto key : nums)
        {
            m[key]++;
        }
        vector<int>res;
        for(auto key : nums)
        {
            if(m[key]==0)
            {
                continue;
            }
            m[key]--;
            if(m[2*key]!=0)
            {
                res.push_back(key);
                m[2*key]--;
            }
            else
            {
                return {};
            }
        }
        return res;
        
    }
};