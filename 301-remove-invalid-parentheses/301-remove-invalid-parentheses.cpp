class Solution {
public:
    unordered_set<string>sett;
    int get_min_removals(string s)
    {
        stack<char>st;
        for(auto key : s)
        {
            if(key=='(')
            {
                st.push(key);
            }
            else if(key==')')
            {
                if(st.size()==0 || st.top()==')')
                {
                    st.push(key);
                }
                else if(st.top()=='(')
                {
                    st.pop();
                }
            }
        }
        return st.size();
    }
    void generate(string s,int removals,vector<string>&res)
    {
        if(removals == 0 && get_min_removals(s)==0)
        {
            res.push_back(s);
            return;
        }
        for(int i=0;i<s.size();i++)
        {
           if(s[i] >= 'a' && s[i] <= 'z') continue;
            string left = s.substr(0,i);
            string right = s.substr(i+1);
            string str = left + right;
            if(sett.find(str)==sett.end())
            {
                generate(left+right,removals-1,res);  
                sett.insert(str);
            }
        }
    }
    vector<string> removeInvalidParentheses(string s)
    {
        int removals = get_min_removals(s);
        vector<string>res;
        generate(s,removals,res);
        return res;
    }
};