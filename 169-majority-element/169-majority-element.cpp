class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int val = nums[0];
        int count = 1;
        
        for(int i=1;i<nums.size();i++)
        {
            int curr = nums[i];
            if(val == curr)
            {
                count++;
            }
            else
            {
                count--;
                if(count==0)
                {
                    val = curr;
                    count = 1;
                }
            }
        }
        
        return val;
    }
};