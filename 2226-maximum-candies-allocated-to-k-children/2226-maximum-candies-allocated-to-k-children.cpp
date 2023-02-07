class Solution {
public:
    bool help(int candid , vector<int>&nums , long long k)
    {
        long long count = 0;
        for(auto key : nums)
        {
            count = count + (key)/candid;   
        }
        return count >= k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int low = 1;
        int high = 0;
        int res = -1;
        for(auto key : candies)
        {
            high = max(high,key);
        }
        while(low<=high)
        {
            int mid = (low + high)/2;
            bool check = help(mid,candies,k);
            if(check == true)
            {
                res = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        if(res == -1)
        {
            return 0;
        }
        else
        {
            return res;
        }
    }
};