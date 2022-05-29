class Solution {
public:
    int longestOnes(vector<int>& nums, int k) 
    {
        int res = 0;
        int j = 0;
        int count = 0;
        for(int i = 0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                count++;
            }
            while(count>k)
            {
                if(nums[j]==0)
                {
                    count--;
                }
                j++;
            }
            int len = i-j+1;
            res=max(res,len);
        }
        return res;
        
    }
};