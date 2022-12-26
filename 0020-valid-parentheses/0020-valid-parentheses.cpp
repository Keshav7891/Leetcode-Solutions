class Solution {
public:
    bool help(char a , char b)
    {
        if(a=='(' && b==')' || a=='{' && b=='}' || a=='[' && b==']')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isValid(string str) {
        stack<char>s;
        for(auto key : str)
        {
            if(key == '(' || key == '{' || key == '[')
            {
                s.push(key);
            }
            else
            {
                if(s.empty()==true)
                {
                    return false;
                }
                else
                {
                    char ch = s.top();
                    bool check = help(ch,key);
                    if(check == true)
                    {
                        s.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
        if(s.empty()==false)
            return false;
        return true;
    }
};