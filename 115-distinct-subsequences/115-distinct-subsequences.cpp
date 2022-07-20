class Solution {
public:
    int help(string &source , string &target , int i , int j , vector<vector<int>>&dp)
    {
        if(i==source.size())
        {
            if(j==target.size())
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else if(j==target.size())
        {
            return 1;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        
        if(source[i]==target[j])
        {
            int pick = help(source,target,i+1,j+1,dp);
            int not_pick = help(source,target,i+1,j,dp);
            return dp[i][j] = pick+not_pick;
        }
        else
        {
            int not_pick = help(source,target,i+1,j,dp);
            return dp[i][j] = not_pick;
        }
    }
    int numDistinct(string s, string t) 
    {
        vector<vector<int>>dp(s.size()+1,vector<int>(t.size()+1,-1));
        int res = help(s,t,0,0,dp);
        return res;
        
    }
};