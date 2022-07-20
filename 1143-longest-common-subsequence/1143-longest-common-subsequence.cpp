class Solution {
public:
    int help(string &str1 , string &str2 , int i , int j , vector<vector<int>>&dp)
    {
        if(i==0 || j==0)
        {
            return 0;
        }
        
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        
        if(str1[i-1]==str2[j-1])
        {
            return dp[i][j] = 1 + help(str1,str2,i-1,j-1,dp);
        }
        else
        {
            return dp[i][j] = max(help(str1,str2,i-1,j,dp) , help(str1,str2,i,j-1,dp));
        }
    }
    int longestCommonSubsequence(string text1, string text2) 
    {
        
        vector<vector<int>>dp(text1.size()+1,vector<int>(text2.size()+1,-1));
        
        return help(text1,text2,text1.size(),text2.size(),dp);
        
    }
};