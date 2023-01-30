class Solution {
public:
    const int mod = 1e9 + 7;
    long long int help(int index , int path , unordered_map<int,int>&path1 , unordered_map<int,int>&path2 , vector<int>&nums1 , vector<int>&nums2 , vector<vector<long long int>>&dp)
    {
        if(path == 1)
        {
            if(index >= nums1.size() )
            {
                return 0;
            }
        }
        else if(path == 2 )
        {
            if(index >= nums2.size())
            {
                return 0;
            }
        }
        
        if(dp[index][path]!=-1)
        {
            return dp[index][path];
        }
        
        if(path == 1)
        {
            long long int op1 = nums1[index] + help(index+1 , 1 , path1 , path2 , nums1 , nums2 , dp);
            long long int op2 = 0;
            if(path2.find( nums1[index] ) != path2.end())
            {
                op2 = nums1[index] + help( path2[nums1[index]]+1 , 2 , path1 , path2 , nums1 , nums2 , dp);
            }
            return dp[index][path] = max(op1,op2);
        }
        else
        {
            long long int op1 = nums2[index] + help(index+1 , 2 , path1 , path2 , nums1 , nums2 , dp);
            long long int op2 = 0;
            if(path1.find( nums2[index] ) != path1.end())
            {
                op2 = nums2[index] + help( path1[nums2[index]]+1 , 1 , path1 , path2 , nums1 , nums2 , dp);
            }
            return dp[index][path] = max(op1,op2);
        }
    }
    
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>path1;
        unordered_map<int,int>path2;
        
        for(int i=0;i<nums1.size();i++)
        {
            path1[nums1[i]] = i;
        }
        
        for(int i=0;i<nums2.size();i++)
        {
            path2[nums2[i]] = i;
        }
         
        int maxLen = max(nums1.size(),nums2.size());
        vector<vector<long long int>>dp(maxLen+1,vector<long long int>(2+1,-1));
        
        long long int res1 = (help(0,1,path1,path2,nums1,nums2,dp))%mod;
        long long int res2 = (help(0,2,path1,path2,nums1,nums2,dp))%mod;
        
        return max(res1,res2)%mod;
    }
};