class Solution {
public:
    bool matching(char a , char b)
    {
        if(a=='{' && b=='}' || a=='[' && b==']' || a=='(' && b==')')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isValid(string str) 
    {
        stack<int>s;
        for(int i=0;i<str.length();i++)
        {
            if(str[i]=='{' || str[i]=='[' || str[i]=='(')
            {
                s.push(str[i]);
            }
            else
            {
                if(s.size()==0)
                {
                    return false;
                }
                else if(matching(s.top(),str[i])==false)
                {
                    return false;
                }
                else
                {
                    s.pop();
                }
            }
        }
        return (s.size()==0);
        
    }
};