class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) 
    {
        vector<int>res(nums.size());
        int low = 0;
        int high = nums.size()-1;
        int k = nums.size()-1;
        
        while(low<=high)
        {
            int val1 = nums[low]*nums[low];
            int val2 = nums[high]*nums[high];
            
            if(val2>val1)
            {
                res[k] = val2;
                k--;
                high--;
            }
            else
            {
                res[k] = val1;
                k--;
                low++;
            }
        }
        
        return res;
        
        
    }
};