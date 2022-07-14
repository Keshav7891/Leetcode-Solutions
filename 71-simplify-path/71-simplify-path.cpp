class Solution {
public:
    string simplifyPath(string path) 
    {
        stack<string>st;
        int i=0;
        for(int i=0;i<path.size();i++)
        {
            char key = path[i];
            if(key=='/')
            {
                continue;
            }
            string temp="";
            while(i<path.size() && path[i]!='/')
            {
                temp=temp+path[i];
                i++;
            }
            if(temp==".")
            {
                continue;
            }
            else if(temp=="..")
            {
                if(st.empty()==false)
                {
                    st.pop();
                }
            }
            else
            {
                st.push(temp);
            }
        }
        string res = "";
        while(st.empty()==false)
        {
            string temp=st.top();
            st.pop();
            res = '/' + temp + res;
        }
        if(res.size()==0)
        {
            return "/";
        }

        return res;

    }
};