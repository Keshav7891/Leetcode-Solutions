class Solution {
public:
    int help(int i , int M , vector<int>&nums , vector<vector<int>>&dp)
    {
        if(i>=nums.size())
        {
            return 0;
        }
        if(dp[i][M]!=-1)
        {
            return dp[i][M];
        }
        int score = INT_MIN;
        int total = 0;
        for(int j=0;j<2*M;j++)
        {
            if(i+j<nums.size())
            {
                total = total + nums[i+j];
            }
            int op = total - help(i+j+1 , max(M,j+1) , nums , dp);
            score = max(score,op);
        }
        
        return dp[i][M] = score;
        
    }
    int stoneGameII(vector<int>& piles) 
    {
        vector<vector<int>>dp(piles.size()+1,vector<int>(piles.size()+1,-1));
        int diff = help(0,1,piles , dp);
        int sum = 0;
        for(auto key :  piles)
        {
            sum = sum + key;
        }
        int score = (sum + diff)/2;
        return score;
    }
};