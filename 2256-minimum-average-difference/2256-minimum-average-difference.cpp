class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long total = 0;
        long long n = nums.size();
        for(auto key : nums)
        {
            total = total + key;
        }
        int index = 0;
        long long res = INT_MAX;
        long long sum = 0;
        for(int i=0;i<nums.size();i++)
        {
            sum = sum + nums[i];
            int left = sum / (i+1);
            int right;
            if(i == nums.size()-1)
            {
                right = 0;
            }
            else
            {
                right = (total - sum) / (n - i - 1);
            }
            int candid = abs(left - right);
            //cout<<left<<" - "<<right<<" = "<<candid<<endl;
            if(candid < res)
            {
                res = candid;
                index = i;
            }
        }
        return index;
    }
};