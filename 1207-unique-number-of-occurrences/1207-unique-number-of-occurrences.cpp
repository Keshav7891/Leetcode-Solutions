class Solution {
public:
    bool uniqueOccurrences(vector<int>& nums) 
    {
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        unordered_set<int>s;
        for(auto e:m)
        {
            if(s.find(e.second)!=s.end())
            {
                return false;
            }
            s.insert(e.second);
        }
        return true;
        
    }
};