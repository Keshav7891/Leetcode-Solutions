class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) 
    {
        vector<int>sub;
        for(int i=0;i<nums.size();i++)
        {
            int sum = 0;
            for(int j=i;j<nums.size();j++)
            {
                sum = (sum + nums[j])%1000000007;
                sub.push_back(sum);
            }
        }
        sort(sub.begin(),sub.end());
        int sum = 0;
        for(int i=0;i<sub.size();i++)
        {
            if(i>=left-1 && i<=right-1)
            {
                //cout<<sub[i]<<endl;
                sum = (sum + sub[i])%1000000007;
            }
        }
        return sum;
    }
};