class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int max1 = INT_MIN;
        int max2 = INT_MIN;
        int max3 = INT_MIN;
        for(int i=nums.size()-1;i>=0;i--)
        {
            
            int curr = nums[i];
            if(curr > max1)
            {
                max1 = curr;
                
            }
            else if(curr > max2 && curr < max1)
            {
                max2 = curr;
            }
            else if( curr > max3 && curr < max1 && curr < max2)
            {
                max3 = curr;
            }
            if(max1 != INT_MIN && max2 != INT_MIN && max3 != INT_MIN)
            {
                return true;
            }
        }
        return false;
    }
};