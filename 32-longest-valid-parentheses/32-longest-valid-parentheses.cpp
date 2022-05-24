class Solution {
public:
    int longestValidParentheses(string s) 
    {
        int res=0,open=0,close=0,len;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                open++;
            }
            else
            {
                close++;
            }
            if(open==close)
            {
                len = open+close;
                res=max(res,len);
            }
            if(close>open)
            {
                open=0;
                close=0;
            }
        }
        open=0;close=0;
        for(int i=s.length()-1;i>=0;i--)
        {
            if(s[i]=='(')
            {
                open++;
            }
            else
            {
                close++;
            }
            if(open==close)
            {
                len = open+close;
                res=max(res,len);
            }
            if(open>close)
            {
                open=0;
                close=0;
            }
        }
        return res;
        
        
    }
};