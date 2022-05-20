class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) 
    {
        long res=0;
        for(auto key : nums)
        {
            res=res^key;
        }
        long rsb = res & -res;
        long x=0, y=0;
        for(auto key : nums)
        {
            if((key & rsb) == 0)
            {
                x=x^key;
            }
            else
            {
                y=y^key;
            }
        }
        int a=(int)x;
        int b=(int)y;
        return {a,b};
        
    }
};