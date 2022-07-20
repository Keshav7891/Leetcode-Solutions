class Solution {
public:
    
    int help(string str1,string str2, int i, int j, vector<vector<int>> &dp)
    {
        if(i==0)
        {
            return j;
        }
        if(j==0)
        {
            return i;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(str1[i-1]==str2[j-1])
        {
            dp[i][j] = 0 + help(str1,str2,i-1,j-1,dp);
            return dp[i][j];
        }
        else
        {
            int insrt = 1 + help(str1,str2,i,j-1,dp);
            int dlt = 1 + help(str1,str2,i-1,j,dp);
            int rplc = 1 + help(str1,str2,i-1,j-1,dp);
            int res = min(rplc,min(insrt,dlt));
            dp[i][j] = res;
            return dp[i][j];
        }
    }
    int minDistance(string word1, string word2)
    {
        vector<vector<int>>dp(word1.size()+1,vector<int>(word2.size()+1,-1));
        int res = help(word1,word2,word1.size(),word2.size(),dp);
        return res;
        
    }
};