class Solution {
public:
    int check(int limit,vector<int> piles){
        int count=0;
        for(auto p : piles)
        {
            count += p/limit;
            if(p%limit) count++;
        }
        return count;
    }
    int smallestDivisor(vector<int>& nums, int h)
    {
        int low = 1;
        int high = INT_MIN;
        int res = INT_MAX;
        
        for(auto key : nums)
        {
            high=max(high,key);
        }
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            int speed = check(mid,nums);
            if(speed<=h)
            {
                res=min(res,mid);
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        
        return res;
        
    }
    
};