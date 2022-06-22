class Solution {
public:
    int maxChunksToSorted(vector<int>& nums)
    {
        int impact = INT_MIN;
        int count = 0;
        for(int i=0;i<nums.size();i++)
        {
            impact = max(impact,nums[i]);
            if(impact == i)
            {
                count++;
            }
        }
        return count;
    }
};