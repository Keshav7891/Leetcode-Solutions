class Solution {
public:
    vector<string>res;
    void help(int index , string str ,string path , unordered_set<string>&s)
    {
        if(index == str.size())
        {
            path.pop_back();
            res.push_back(path);
            return ;
        }
        string curr = "";
        for(int i=index;i<str.size();i++)
        {
            curr = curr + str[i];
            if(s.find(curr)!=s.end())
            {
                help(i+1,str,path + curr + ' ',s);
            }
        }
    }
    vector<string> wordBreak(string str, vector<string>& wordDict) {
        unordered_set<string>s;
        for(auto key : wordDict)
        {
            s.insert(key);
        }
        help(0,str,"",s);
        return res;
    }
};