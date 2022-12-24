class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {
            int curr = nums[i];
            int rem = target - curr;
            if(m.find(rem)!=m.end())
            {
                return {i,m[rem]};
            }
            m[curr] = i;
        }
        return {};
    }
};