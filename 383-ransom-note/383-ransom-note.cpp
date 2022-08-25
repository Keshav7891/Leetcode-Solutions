class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int>freq(26,0);
        for(auto key : ransomNote)
        {
            freq[key-'a']++;
        }
        for(auto key : magazine)
        {
            if(freq[key-'a']==0)
            {
                continue;
            }
            else
            {
                freq[key-'a']--;
            }
        }
        for(auto key : freq)
        {
            if(key!=0)
            {
                return false;
            }
        }
        return true;
    }
};