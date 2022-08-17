class Solution {
public:
    bool help(int candid , vector<int>& nums , int reqbouquets , int window)
    {
        int bouquets = 0;
        int flowers = 0;
        int res = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<=candid)
            {
                flowers++;
            }
            else 
            {
                flowers=0;
            }
            if(flowers==window)
            {
                bouquets++;
                flowers = 0;
            }
        }
        return (bouquets>=reqbouquets);
    }
    int minDays(vector<int>& nums, int m, int k)
    {
        int low = 1;
        int high = INT_MIN;
        for(auto key : nums)
        {
            high = max(high,key);
        }
        int res = -1;
        while(low<=high)
        {
            int mid = (low+high)/2;
            bool check = help(mid,nums,m,k);
            if(check == true)
            {
                res = mid;
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        return res;
    }
};