class Solution {
public:
    bool help(int mid , vector<int>& nums, double hour)
    {
        double time = 0;
        for(auto key : nums)
        {
            time = ceil(time);
            double t = key / (mid * 1.0);
            //cout<<t<<" ";
            time = time + t;
        }
        //cout<<endl;
        //cout<<mid<<" "<<time<<endl;
        return time <= hour;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low = 1;
        int high = 1e9;
        bool flag = false;
        int res = -1;
        while(low <= high)
        {
            int mid = (low + high)/2;
            //cout<<mid<<endl;
            bool check = help(mid,dist,hour);
            if(check == true)
            {
                res = mid;
                high = mid-1;
            }
            else
            {
                low = mid + 1;
            }
        }
        if(res != -1)   return res;
        return -1;
    }
};