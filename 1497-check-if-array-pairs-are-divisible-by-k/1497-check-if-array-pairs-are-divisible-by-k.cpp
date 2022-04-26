class Solution {
public:
    bool canArrange(vector<int>& nums, int k)
    {
        unordered_map<int,int>m;
        for(auto key : nums)
        {
            int rem = ((key%k)+k)%k;
            m[rem]++;
        }
        for(int i=0;i<k;i++)
        {
            if(i==0)
            {
                if(m[i]%2!=0)
                {
                    return false;
                }
                continue;
            }
            else
            {
                if(m[i]!=m[k-i])
                {
                    return false;
                }
            }
        }
        return true;
        
    }
};