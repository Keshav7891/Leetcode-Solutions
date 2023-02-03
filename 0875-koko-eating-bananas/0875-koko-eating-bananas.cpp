class Solution {
public:
    
    bool help(int candid , vector<int>&nums , int target)
    {
        long long int count = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%candid == 0)
            {
                count = count + nums[i]/candid;
            }
            else
            {
                count = count + nums[i]/candid + 1; 
            }
        }
        
        return count<=target;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int low = 1;
        int high = 0;
        int res = -1;
        
        for(auto key : piles)
        {
            high = max(high,key);
        }
        
        while(low<=high)
        {
            long long int mid = (low + high)/2;
            long long int candid = mid;

            bool check = help(candid,piles,h);
            if(check == true)
            {
                res = candid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        
        return res;
        
    }
};