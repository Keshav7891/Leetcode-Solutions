class Solution {
public:
    bool help(int index , string str , unordered_set<string>&s , vector<int>&dp)
    {
        if(index >= str.size())
        {
            return true;
        }
        if(dp[index]!=-1)
        {
            return dp[index];
        }
        string curr = "";
        bool res = false;
        for(int i=index;i<str.size();i++)
        {
            curr = curr + str[i];
            if(s.find(curr)!=s.end())
            {
                res = res || help(i+1,str,s,dp);
            }
        }
        return dp[index] = res;
    }
    bool wordBreak(string str, vector<string>& wordDict) {
        vector<int>dp(str.size()+1,-1);
        unordered_set<string>s;
        for(auto key : wordDict)
        {
            s.insert(key);
        }
        bool res = help(0,str,s,dp);
        return res;
    }
};