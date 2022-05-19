class Solution {
public:
    bool solve(string& s, unordered_set<string>& st, vector<int>& dp, int idx) {
        if (idx >= s.length()) return true;
        else if (dp[idx] != -1) return dp[idx]; // if it's been visited before
        
        for (int i = 1; i < (s.length() - idx + 1); i++) {
            if (st.find(s.substr(idx, i)) != st.end()) {
                if (solve(s, st, dp, idx+i)) return dp[idx] = true;
            }
        }
        return dp[idx] = false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        for (auto& word: wordDict) st.insert(word);
        
        vector<int> dp(s.length(), -1);
        
        return solve(s, st, dp, 0);
    }
};