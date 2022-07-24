class Solution {
public:
    
    int help(vector<int>&nums,int i , int j , vector<vector<int>>&dp)
    {
        if(i>j)
        {
            return 0;
        }
        
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        
        int res = INT_MAX;
        for(int index = i;index<=j; index++)
        {
            int cost = nums[j+1]-nums[i-1] + help(nums,i,index-1,dp) + help(nums,index+1,j,dp);
            //cout<<cost<<endl;
            res = min(res,cost);
        }
        
        return dp[i][j] = res;
        
    }
    
    int minCost(int n, vector<int>& cuts) {
        vector<int>nums;
        nums.push_back(0);
        for(auto key : cuts)
        {
            nums.push_back(key);
        }
        nums.push_back(n);
        sort(nums.begin(),nums.end());
        vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        int res = help(nums,1,cuts.size(),dp);
        return res;
    }
};