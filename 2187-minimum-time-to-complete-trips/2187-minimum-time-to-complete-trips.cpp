class Solution {
public:
    bool help(long long int  candid , vector<int>&nums ,int totalTrips)
    {
        long long int count = 0;
        for(auto key : nums)
        {
            count = count + candid/key;
        }
        
        //cout<<candid<<" "<<totalTrips<<endl;
        return totalTrips <= count;
    }
    long long minimumTime(vector<int>& nums, int totalTrips) {
        int mine = INT_MAX;
        int maxe = INT_MIN;
        long long int res = -1;
        
        for(auto key : nums)
        {
            mine = min(mine,key);
            maxe = max(maxe,key);
        }
        
        long long int low = mine;
        long long int high = 1e14;
        
        //cout<<low<<" "<<high<<endl;
        
        while(low<=high)
        {
            long long int mid = (low + high)/2;
            bool check = help(mid,nums,totalTrips);
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