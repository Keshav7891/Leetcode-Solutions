class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>>st;
        for(int i=0;i<s.size();i++)
        {
            char key = s[i];
            if(key == '(')
            {
                st.push({key,i});
            }
            else if(key ==')')
            {
                if(st.empty()==true)
                {
                    s[i]='*';
                }
                else if(st.empty()==false && st.top().first=='(')
                {
                    st.pop();
                }
                else if(st.empty()==false && st.top().first==')')
                {
                    st.push({key,i});
                }
            }
            else
            {
                continue;
            }
        }
        
        if(st.empty()==false)
        {
            while(st.empty()==false)
            {
                int index = st.top().second;
                st.pop();
                s[index]='*';
            }
        }
        
        
        s.erase(remove(s.begin(), s.end(), '*'), s.end());
        return s;
    }
};