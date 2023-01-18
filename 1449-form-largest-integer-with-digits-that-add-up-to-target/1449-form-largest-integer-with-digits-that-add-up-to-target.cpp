class Solution {
public:
    string help(vector<int>& cost , int target , unordered_map<int,string>&dp)
    {
        if(target == 0)
        {
            return "";
        }
        else if(target < 0)
        {
            return "0";
        }
        if(dp.find(target)!=dp.end())
        {
            return dp[target];
        }
        string curr = "";
        string res = "0";
        for(int i=0;i<9;i++)
        {
            curr = help(cost,target-cost[i],dp);
            if(curr == "0") continue;
            curr = to_string(i+1) + curr;
            if(curr.size() >= res.size())
            {
                res = curr;
            }
        }
        return dp[target] = res;
    }
    string largestNumber(vector<int>& cost, int target) {
        unordered_map<int,string>dp;
        return help(cost,target,dp);
    }
};