class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long int>s;
        for(auto key : tokens)
        {
            if(key == "+" || key == "-" || key == "*" || key == "/")
            {
                long long int b = s.top();
                s.pop();
                long long int a = s.top();
                s.pop();
                long long int res;
                
                if(key == "+")
                {
                    res = a + b;
                }
                else if(key == "-")
                {
                    res = a - b;                 
                }
                else if(key == "*")
                {
                    res = a * b;
                }
                else if(key == "/")
                {
                    res = a / b;
                }
                
                s.push(res);
            }
            else
            {
                s.push(stoi(key));
            }
        }
        return s.top();
    }
};