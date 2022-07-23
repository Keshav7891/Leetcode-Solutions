class Solution {
public:
    int dp[501][501] ;
    int solve(vector<int>&nums , int s , int e){
        if(s == e) return 0 ; 
        if(dp[s][e] != -1) return dp[s][e] ;
        
        int sum = 0 , left = 0 , right = 0 ;
        for(int i = s ; i <= e ; ++i) sum += nums[i] ;
        
        int op1 = 0 , op2 = 0 ;
        for(int i = s ; i < e ; ++i ){
            left += nums[i] , right = sum - left ;
            if(left <= right) op1 = max(op1,left + solve(nums,s,i)) ;
            if(left >= right) op2 = max(op2,right + solve(nums,i+1,e)) ;
        }
        
        return dp[s][e] = max(op1,op2) ;
    }
    int stoneGameV(vector<int>& nums) {
        memset(dp,-1,sizeof(dp)) ;
        return solve(nums,0,nums.size() - 1) ;
    }
};