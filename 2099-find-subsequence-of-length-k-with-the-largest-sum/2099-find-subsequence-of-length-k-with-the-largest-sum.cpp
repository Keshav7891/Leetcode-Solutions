class Solution {
public:
    vector<int> maxSubsequence(vector<int>& arr, int k) 
    {
        vector<int>nums = arr;
        unordered_map<int,int>m;
        sort(nums.begin(),nums.end(),greater<int>());
        for(int i=0;i<k;i++)
        {
            m[nums[i]]++;
        }
        vector<int>res;
        for(auto key : arr)
        {
            if(m.find(key)!=m.end())
            {
                if(m[key]>0)
                {
                    res.push_back(key);
                    m[key]--;
                }
            }
        }
        return res;
    }
};