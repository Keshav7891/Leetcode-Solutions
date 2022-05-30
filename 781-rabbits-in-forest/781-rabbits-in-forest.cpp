class Solution {
public:
    int numRabbits(vector<int>& nums) 
    {
        int res = 0;
        unordered_map<int,int>m;
        for(auto key : nums)
        {
            m[key]++;
        }
        for(auto key : m)
        {
            int size = key.first + 1;
            int candidates = key.second;
            double temp = candidates * 1.0 / size * 1.0;
            res = res + ceil(temp) * size;
        }
        return res;   
    }
};