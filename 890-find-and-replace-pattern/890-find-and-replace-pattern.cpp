class Solution {
public:
    bool check(string &key , string &pattern)
    {
        unordered_map<char,char>m;
        for(int i=0;i<pattern.size();i++)
        {
            if(m.find(pattern[i])==m.end())
            {
                m[pattern[i]]=key[i];
            }
            else
            {
                if(m[pattern[i]]==key[i])
                {
                   continue;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern)
    {
        vector<string>res;
        for(auto key : words)
        {
            if(check(key,pattern)==true && check(pattern,key)==true)
            {
                res.push_back(key);
            }
        }
        return res;
        
    }
};