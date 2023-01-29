class Solution {
public:
    int help(int len , int copied , int target)
    {
        if(len == target)
        {
            return 0;
        }
        else if(len > target)
        {
            return INT_MAX/2;
        }
        
        int copy_paste = 2 + help(len + len , len , target);
        int paste =  1 + help(len + copied , copied , target);
        
        return min({copy_paste , paste});
    }
    int minSteps(int n) 
    {
        if(n==0 || n==1)
        {
            return 0;
        }
        return 1 + help(1,1,n);
        
    }
};