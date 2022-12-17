class Solution {
public:
    int help(int index , int n , string vowels , vector<vector<int>>&dp)
    {
        if(n == 0)
        {
            return 1;
        }
        if(index == vowels.size())
        {
            if(n == 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        
        if(dp[index][n]!=-1)
        {
            return dp[index][n];
        }
            
        int pick = help(index,n-1,vowels,dp);
        int not_pick = help(index+1,n,vowels,dp);
            
        return dp[index][n] = pick + not_pick;
        
    }
    int countVowelStrings(int n) {
        string vowels = "aeiou";
        vector<vector<int>>dp(vowels.size()+1,vector<int>(n+1,-1));
        int res = help(0,n,vowels,dp);
        return res;
    }
};