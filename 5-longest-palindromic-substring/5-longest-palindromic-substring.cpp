class Solution {
public:
    string longestPalindrome(string s)
    {
        string res = " ";
        int start,len;
        vector<vector<bool>>dp(s.size(),vector<bool>(s.size()));
        for(int gap=0;gap<s.size();gap++)
        {
            for(int i=0,j=gap;j<s.size();i++,j++)
            {
                if(gap==0)
                {
                    dp[i][j]=true;
                }
                else if (gap==1)
                {
                    if(s[i]==s[j])
                    {
                        dp[i][j]=true;
                    }
                    else
                    {
                        dp[i][j]=false;
                    }
                }
                else
                {
                    if(s[i]==s[j])
                    {
                        if(dp[i+1][j-1]==true)
                        {
                            dp[i][j]=true;
                        }
                        else
                        {
                            dp[i][j]=false;
                        }
                    }
                    else
                    {
                        dp[i][j]=false;
                    }
                }
                
                if(dp[i][j])
                {
                    start = i;
                    len = j-i+1;
                }
                
            }
        }
        res = s.substr(start,len);
        return res;
        
    }
};