class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>pos;
        vector<int>neg;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<0)
            {
                neg.push_back(nums[i]);
            }
            else
            {
                pos.push_back(nums[i]);
            }
        }
        int c1 = 0;
        int c2 = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(i%2==0)
            {
                nums[i] = pos[c1];
                c1++;
            }
            else
            {
                nums[i] = neg[c2];
                c2++;
            }
        }
        return nums;
    }
};