class Solution {
public:
    const int mod = 1e9+7;
    long long int help(int n,char curr,vector<vector<int>>&dp)
    {
        if(n==0)
        {
            return 1;
        }
        if(dp[n][curr-'a']!=-1)
        {
            return dp[n][curr-'a'];
        }
        long long int res = 0;
        if(curr == 'a')
        {
            int op1 = help(n-1,'e',dp);
            res = (res + op1)%mod;
        }
        else if(curr == 'e')
        {
            int op1 = help(n-1,'a',dp);
            int op2 = help(n-1,'i',dp);
            res = (res + op1 + op2)%mod;
        }
        else if(curr == 'i')
        {
            int op1 = help(n-1,'a',dp);
            int op2 = help(n-1,'e',dp);
            int op3 = help(n-1,'o',dp);
            int op4 = help(n-1,'u',dp);
            res = (res + op1 + op2 + op3 + op4)%mod;
        }
        else if(curr == 'o')
        {
            int op1 = help(n-1,'i',dp);
            int op2 = help(n-1,'u',dp);
            res = (res + op1 + op2)%mod;
        }
        else if(curr == 'u')
        {
            int op1 = help(n-1,'a',dp);
            res = (res + op1)%mod;
        }
        return dp[n][curr-'a'] = res;
    }
    int countVowelPermutation(int n) {
        vector<vector<int>>dp(n+1,vector<int>(26+1,-1));
        return (help(n-1,'a',dp) + help(n-1,'e',dp) + help(n-1,'i',dp) + help(n-1,'o',dp) + help(n-1,'u',dp))%mod;
    }
};