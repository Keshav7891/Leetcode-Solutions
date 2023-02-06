class Solution {
public:
    
    bool help(int candid , vector<int>&nums , int maxOperations)
    {
        int count = 0;
        for(auto key : nums)
        {
            count = count + (key-1)/candid;
        }
        return count <= maxOperations;
    }
    
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low = 1;
        int high = 0;
        for(auto key : nums)
        {
            high = max(high,key);
        }
        int res = 0;
        while(low<=high)
        {
            int mid = (low + high)/2;
            bool check = help(mid,nums,maxOperations);
            if(check == true)
            {
                res = mid;
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