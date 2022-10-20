class Solution {
public:
    vector<int> replaceElements(vector<int>& nums) {
        int rplc = nums[nums.size()-1];
        nums[nums.size()-1] = -1;
        for(int i=nums.size()-2;i>=0;i--)
        {
            int ele = nums[i];
            nums[i] = rplc;
            rplc = max(rplc,ele);
        }
        return nums;
    }
};