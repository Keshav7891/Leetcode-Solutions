class Solution {
public:
    vector<string> help(string digits , unordered_map<int,string>&m)
    {
        if(digits.size() == 0)
        {
            vector<string>res;
            res.push_back("");
            return res;
        }
        char curr = digits[0] - '0';
        string s = m[curr];
        string rem = digits.substr(1);
        
        vector<string>res = help(rem,m);
        vector<string>newRes;
        for(auto key : res)
        {
            for(auto key1 : s)
            {
                newRes.push_back(key1 + key);
            }
        }
        
        return newRes;
        
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0)  return {};
       unordered_map<int,string>m;
        m[2] = "abc";
        m[3] = "def";
        m[4] = "ghi";
        m[5] = "jkl";
        m[6] = "mno";
        m[7] = "pqrs";
        m[8] = "tuv";
        m[9] = "wxyz";
        vector<string>res = help(digits,m);
        return res;
    }
};