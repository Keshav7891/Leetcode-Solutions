class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        for(auto key : s)
        {
            if(key=='(')
            {
                //cout<<"push "<<key<<endl;
                st.push(key);
            }
            else if(key==')')
            {
                if(st.empty()==true || st.top()==')')
                {
                    //cout<<"push "<<key<<endl;
                    st.push(key);
                }
                else
                {
                    //cout<<"pop "<<key<<endl;
                    st.pop();
                }
            }
        }
        return st.size();
    }
};