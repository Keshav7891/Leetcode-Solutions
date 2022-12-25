class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s;
        for(auto key : nums)
        {
            s.insert(key);
        }
        int res = 0;
        int len;
        for(auto key : nums)
        {
            int ele = key - 1;
            if(s.find(ele) == s.end())
            {
                len = 0;
                while(s.find(key)!=s.end())
                {
                    key++;
                    len++;
                }
                res = max(res,len);
            }
        }
        return res;
    }
};