class Solution {
public:
    string removeKdigits(string nums, int k) {
        stack<char> s;
        
        for(auto key : nums)
        {
            while(s.empty()==false && s.top()>key && k>0)
            {
                s.pop();
                k--;
            }
            if(s.empty()==false|| key!='0')
            {
                s.push(key);
            }
        }
        while(s.empty()==false && k>0)
        {
            s.pop();
            k--;
        }
        if(s.empty()==true)
        {
            return "0";
        }
        string res="";
        while(s.empty()==false)
        {
            res+=s.top();
            s.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};