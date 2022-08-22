class Solution {
public:
    bool help(int n)
    {
        if(n==1)
        {
            return true;
        }
        if(n%4!=0)
        {
            return false;
        }
        
        return help(n/4);
    }
    bool isPowerOfFour(int n) {
        if(n==0)
        {
            return false;
        }
        return help(n);
    }
};