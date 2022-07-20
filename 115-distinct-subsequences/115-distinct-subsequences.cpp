class Solution {
public:
    int help(string& source, string& target, int source_index, int target_index, vector<vector<int>>&dp)
    {
        if(source_index == source.size())
        {
            if(target_index < target.size())
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }
        else if(target_index == target.size())
        {
            return 1;
        }
        
        if(dp[source_index][target_index]!=-1) 
        {
            return dp[source_index][target_index];   
        }
        
        if(source[source_index] == target[target_index])  
        {
            int not_pick = help(source,target,source_index+1,target_index,dp);
            int pick = help(source,target,source_index+1,target_index+1,dp);
            return dp[source_index][target_index] = pick + not_pick;
        }
        else
        {
            int not_pick = help(source,target,source_index+1,target_index,dp);
            return dp[source_index][target_index] = not_pick;
        }
    }
    int numDistinct(string s, string t) {
        vector<vector<int>>dp(s.size(),vector<int>(t.size(),-1));
        return help(s, t, 0, 0,dp);
    }
};