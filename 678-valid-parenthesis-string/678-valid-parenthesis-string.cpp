class Solution {
public:
    
    bool help(string s , int i , int open , vector<vector<int>>&dp)
    {
        if(open<0)
        {
            return false;
        }
        if(i==s.size())
        {
            if(open == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        
        if(dp[i][open]!=-1)
        {
            return dp[i][open];
        }
        
        bool choice;
        
        if(s[i]=='(')
        {
            choice = help(s,i+1,open+1,dp);
        }
        else if(s[i]==')')
        {
            choice = help(s,i+1,open-1,dp);
        }
        else if(s[i]=='*')
        {
            int op1 = help(s,i+1,open-1,dp);
            int op2 = help(s,i+1,open+1,dp);
            int op3 = help(s,i+1,open,dp);
            choice = op1 || (op2 || op3);
        }
        
        return dp[i][open] = choice;
    }
    
    bool checkValidString(string s) 
    {
        vector<vector<int>>dp(s.size()+1,vector<int>(s.size()+1,-1));
        int open = 0;
        int index = 0;
        bool res = help(s,0,open,dp);
        return res;
    }
};