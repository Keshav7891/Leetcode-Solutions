class Solution {
public:
    bool help(int diff , vector<int>&nums , int balls)
    {
        bool flag = false;
        int prev_placed = -1;
        for(int i=0;i<nums.size();i++)
        {
            if(flag == false || nums[i] - prev_placed >= diff )
            {
                balls--;
                flag = true;
                prev_placed = nums[i];
            }
        }
        return balls <= 0;
    }
    int maxDistance(vector<int>& nums, int m) {
        sort(nums.begin(),nums.end());
        int res = 0;
        int low = 1;
        int high = nums[nums.size()-1] - nums[0];
        while(low<=high)
        {
            int mid = (low+high)/2;
            bool check = help(mid,nums,m);
            if(check == true)
            {
                res = max(res,mid);
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }
        return res;
    }
};