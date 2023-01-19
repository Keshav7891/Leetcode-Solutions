class Solution {
public:
    int help(string str , unordered_map<string,int>&dp)
    {
        if(str.size()==0)
        {
            return 1;
        }
        if(dp.find(str)!=dp.end())
        {
            return dp[str];
        }
        int paths = 0;
        int op1 = str[0] - '0';
        if(op1 > 0)
        {
            paths = paths + help(str.substr(1),dp);
        }
        int op2 = op1 * 10 + (str[1] - '0');
        if(op1!=0 && op2>=10 && op2<=26 && str.size()>=2)
        {
            paths = paths + help(str.substr(2),dp);
        }
        return dp[str] = paths;
    }
    int numDecodings(string s) {
        unordered_map<string,int>m;
        return help(s,m);
    }
};