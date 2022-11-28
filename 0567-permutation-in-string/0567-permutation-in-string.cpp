class Solution {
public:
    bool checkInclusion(string p, string s)
    {
        if(p.size()>s.size())
        {
            return false;
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
            return true;
        }
        
        for(int i=p.size();i<s.size();i++)
        {
            shash[s[i]-'a']++;
            shash[s[i-p.size()]-'a']--;
            if(phash==shash)
            {
                return true;
            }
        }
        
        return false;
    }
};