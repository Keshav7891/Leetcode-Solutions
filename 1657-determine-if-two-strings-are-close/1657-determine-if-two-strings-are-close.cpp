class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size())
        {
            return false;
        }
        vector<int>freq1(26,0);
        vector<int>freq2(26,0);
        for(auto key : word1)
        {
            freq1[key - 'a']++;
        }
        for(auto key : word2)
        {
            freq2[key - 'a']++;
        }
        if(freq1 == freq2)
        {
            return true;
        }
        for(int i=0;i<freq1.size();i++)
        {
            int f1 = freq1[i];
            int f2 = freq2[i];
            if(f1 == 0 && f2 != 0 || f1 != 0 && f2 == 0)
            {
                return false;
            }
        }
        sort(freq1.begin(),freq1.end());
        sort(freq2.begin(),freq2.end());
         for(int i=0;i<freq1.size();i++)
        {
            int f1 = freq1[i];
            int f2 = freq2[i];
            if(f1!=f2)
            {
                return false;
            }
         }
        return true;
    }
};