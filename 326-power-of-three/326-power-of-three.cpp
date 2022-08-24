class Solution {
public:
    bool help(int n)
    {
        if(n==1)
        {
            return true;
        }
        else if(n%3!=0)
        {
            return false;
        }
        else 
        {
            return help(n/3);
        }
    }
    bool isPowerOfThree(int n) {
        if(n==0)
        {
            return false;
        }
        bool res = help(n);
        return res;
    }
};