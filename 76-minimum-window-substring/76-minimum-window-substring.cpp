class Solution {
public:
    string minWindow(string s, string t)
    {
        string res;
        int res_len = INT_MAX;
        unordered_map<char,int>pattern;
        for(auto key : t)
        {
            pattern[key]++;
        }
        int count = 0;
        int target = t.size();
        unordered_map<char,int>source;
        int i=0;
        int j=0;
        
        while(true)
        {
            bool f1=false;
            bool f2=false;
            while(i<s.size() && count < target)
            {
                char ch = s[i];
                source[ch]++;
                if(pattern[ch]>=source[ch])
                {
                    count++;
                }
                i++;
                f1=true;
                
            }
            while(j<i && count == target)
            {
                string ans = s.substr(j,i-j);
                if(res.size()==0 || ans.size()<res.size())
                {
                    res=ans;
                }
                char ch = s[j];
                source[ch]--;
                if(pattern[ch]>source[ch])
                {
                    count--;
                }
                j++;
                f2=true;
            }
            if(f1==false && f2==false)
            {
                break;
            }
        }
        return res;
        
        
    }
};