class Solution {
public:
    int change(int amount, vector<int>& coins)
    {
        vector<int>dp(amount+1,0);
        dp[0]=1;
        for(int i=0;i<coins.size();i++)
        {
            int coin = coins[i];
            for(int j=0;j<amount+1;j++)
            {
                if(j-coin>=0)
                {
                    dp[j]=dp[j]+dp[j-coin];
                }
            }
        }
        return dp[amount];
        
    }
};