class Solution {
public:
    const int mod = 1e9+7;
    long long int help(int n,char curr,unordered_map<char,unordered_set<char>>&adj,vector<vector<int>>&dp)
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
        for(auto key : adj[curr])
        {
            res = (res + help(n-1,key,adj,dp))%mod;
        }
        return dp[n][curr-'a'] = res;
    }
    int countVowelPermutation(int n) {
        unordered_map<char,unordered_set<char>>m;
        vector<vector<int>>dp(n+1,vector<int>(26+1,-1));
        m['a'].insert('e');
        m['e'].insert('a');
        m['e'].insert('i');
        m['i'].insert('a');
        m['i'].insert('e');
        m['i'].insert('o');
        m['i'].insert('u');
        m['o'].insert('i');
        m['o'].insert('u');
        m['u'].insert('a');
        return (help(n-1,'a',m,dp) + help(n-1,'e',m,dp) + help(n-1,'i',m,dp) + help(n-1,'o',m,dp) + help(n-1,'u',m,dp))%mod;
    }
};