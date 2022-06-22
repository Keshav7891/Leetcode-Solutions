class Solution {
public:
    int countPrimes(int n) 
    {
        
        vector<bool>nums(n+1,true);
        nums[0]=false;
        nums[1]=false;
        
        for(int i=0;i*i<=n;i++)
        {
            if(nums[i]!=false)
            {
                for(int j = i+i;j<=n;j=j+i)
                {
                    nums[j]=false;
                }
            }
        }
        
        int res = 0;
        for(int i=0;i<n;i++)
        {
            //cout<<i<<nums[i]<<endl;
            if(nums[i]==true)
            {
                res++;
            }
        }
        return res;
        
    }
};