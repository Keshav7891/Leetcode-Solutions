class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int>s;
        for(auto key : nums)
        {
            if(s.find(key)!=s.end())
            {
                return true;
            }
            else
            {
                s.insert(key);
            }
        }
        return false;
    }
        
};