class Solution {
public:
    bool backspaceCompare(string s, string t) 
    {
        stack<char>one;
        stack<char>two;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='#')
            {
                if(one.empty()==false)
                {
                    one.pop();
                }
            }
            if(s[i]!='#')
            {
                one.push(s[i]);
            }
        }
        for(int i=0;i<t.length();i++)
        {
            if(t[i]=='#')
            {
                if(two.empty()==false)
                {
                    two.pop();
                }
            }
            if(t[i]!='#')
            {
                two.push(t[i]);
            }
        }
        return one==two;
        
    }
};