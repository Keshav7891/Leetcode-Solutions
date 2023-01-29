class Solution {
public:
    int help(int index, int end , vector<vector<int>>& pairs , vector<vector<int>>&dp)
    {
        if(index == pairs.size())
        {
            return 0;
        }
        
        if(dp[index][end+1000]!=-1)
        {
            return dp[index][end+1000];
        }
        
        int currStart = pairs[index][0];
        int currEnd = pairs[index][1];
        
        int op1 = 0 + help(index+1,end,pairs,dp);
        int op2 = 0;
        if(end < currStart)
        {
            op2 = 1 + help(index+1,currEnd,pairs,dp);
        }
        return dp[index][end+1000] = max(op1,op2);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        vector<vector<int>>dp(pairs.size()+1,vector<int>(2000 + 1 , -1));
        sort(pairs.begin(),pairs.end());
        return help(0,-1000,pairs,dp);
    }
};