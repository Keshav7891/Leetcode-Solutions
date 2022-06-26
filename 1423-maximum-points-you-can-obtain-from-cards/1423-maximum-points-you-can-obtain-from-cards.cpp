class Solution {
public:
    int maxScore(vector<int>& nums, int k)
    {
        int res = INT_MIN;
        int sum = 0;
        int i=0;
        int j=nums.size()-1;
        for(i=0;i<k;i++)
        {
            sum = sum + nums[i];
        }
        i--;
        res = max(res,sum);
        while(k!=0)
        {
            cout<<sum<<"-"<<nums[i]<<'+'<<nums[j]<<endl;
            sum = sum - nums[i];
            sum = sum + nums[j];
            i--;
            j--;
            k--;
            res = max(res,sum);
        }
        
        return res;
    }
};