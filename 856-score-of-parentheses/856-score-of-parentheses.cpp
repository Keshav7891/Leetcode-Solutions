class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>st;
        
        for(auto key : s)
        {
            if(key=='(')
            {
                st.push(-1);
            }
            else if(key=')')
            {
                if(st.empty()==false && st.top()==-1)
                {
                    st.pop();
                    st.push(1);
                }
                else if (st.empty()==false && st.top()!=-1)
                {
                    int sum=0;
                    while(st.top()!=-1)
                    {
                        sum=sum+st.top();
                        st.pop();
                    }
                    st.pop();
                    st.push(2*sum);
                }
            }
        }
        int res = 0;
        while(st.empty()==false)
        {
            int temp = st.top();
            res = res + temp;
            st.pop();
        }
        return res;
    }
};