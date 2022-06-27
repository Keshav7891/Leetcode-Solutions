class Solution {
public:
    vector<int> findAnagrams(string s, string p) 
    {
        vector<int>res;
        
        if(p.size()>s.size())
        {
            return res;
        }
        
        vector<int>phash(26,0);
        vector<int>shash(26,0);
        
        for(auto key : p)
        {
            phash[key-'a']++;
        }
        
        for(int i=0;i<p.size();i++)
        {
            shash[s[i]-'a']++;
        }
        
        if(phash==shash)
        {
            res.push_back(0);
        }
        
        for(int i=p.size();i<s.size();i++)
        {
            shash[s[i]-'a']++;
            shash[s[i-p.size()]-'a']--;
            if(phash==shash)
            {
                res.push_back(i-p.size()+1);
            }
        }
        
        return res;
        
        
        
    }
};