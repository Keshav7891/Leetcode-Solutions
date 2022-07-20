class Solution {
public:
    bool help(string &source , string &target , int i , int j , vector<vector<int>>&dp)
    {
        if(i==0)
        {
            if(j==0)
            {
                return true;
            }
            else
            {
                
                return false;
            }
        }
        if(j==0)
        {
            if(source[i-1]=='*')
            {
                while(i>0)
                {
                    if(source[i-1]!='*')
                    {
                        return false;
                    }
                    i--;
                }
                return true;
            }
            else
            {
                return false;
            }
        }
        
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        
        if(source[i-1]==target[j-1])
        {
            return dp[i][j] = help(source,target,i-1,j-1,dp);
        }
        else
        {
            if(source[i-1]=='?')
            {
                return dp[i][j] = help(source,target,i-1,j-1,dp);
            }
            else if(source[i-1]=='*')
            {

                return dp[i][j] = help(source,target,i-1,j,dp) || help(source,target,i,j-1,dp);
            }
            else
            {
                return dp[i][j] = false;
            }
        }
        
    }
    bool isMatch(string s, string p)
    {
        vector<vector<int>>dp(p.size()+1,vector<int>(s.size()+1,-1));
        bool res = help(p,s,p.size(),s.size(),dp);
        return res;
    }
};