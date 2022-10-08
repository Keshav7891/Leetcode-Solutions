class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int x = 1;
        sort(nums.begin(),nums.end());
        for(auto key : nums)
        {
            if(key < x)
            {
                continue;
            }
            else if (key == x)
            {
                x++;
            }
            else if(key > x)
            {
                return x;
            }
        }
        return x;
    }
};