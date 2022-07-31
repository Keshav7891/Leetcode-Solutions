class Solution {
public:
    int minimumOperations(vector<int>& nums)
    {
        unordered_set<int>s;
        for(auto key : nums)
        {
            if(key!=0)
            {
                s.insert(key);
            }
        }
        return s.size();
    }
};