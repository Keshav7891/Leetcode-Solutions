class Solution {
public:
    bool help(string s1 , string s2 , unordered_map<string,bool>&dp)
    {
        if(s1.size()==1)
        {
            return s1==s2;
        }
        if(s1==s2)
        {
            return true;
        }
        
        string key = s1+s2;
        if(dp.find(key)!=dp.end())
        {
            return dp[key];
        }
        
        
        int n = s1.size();
        
        for(int i=1;i<n;i++)
        {
            string x = s1.substr(0,i);
            string y = s1.substr(i);
            
            string x1 = s2.substr(0,i);
            string y1 = s2.substr(i);
            
            string p = s2.substr(n-i);
            string q = s2.substr(0,n-i);
            
            if((help(x,x1,dp)==true && help(y,y1,dp)==true) || (help(x,p,dp)==true && help(y,q,dp)==true))
            {
                return dp[key] = true;
            }
        }
        
        return dp[key] = false;
    }
    bool isScramble(string s1, string s2)
    {
        unordered_map<string,bool>dp;
        bool res = help(s1,s2,dp);
        return res;
    }
};