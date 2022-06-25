class Solution {
public:
    int check(vector<int>&nums,int speed)
    {
        int st=1;
        int sum=0;
        for(auto key : nums)
        {
            sum=sum+key;
            if(sum>speed)
            {
                sum=key;
                st++;
            }
        }
        return st;
    }
    int shipWithinDays(vector<int>& nums , int limit) {
        int high=0;
        int low=INT_MIN;
        for(auto key : nums)
        {
            high=high+key;
            low=max(low,key);
        }
        int res = INT_MAX;
        while(low<=high)
        {
            int mid = (low+high)/2;
            int st = check(nums,mid);
            if(st<=limit)
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