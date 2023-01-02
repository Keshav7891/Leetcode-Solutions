class Solution {
public:
    bool detectCapitalUse(string word) 
    {
        bool first = isupper(word[0]);
        bool is_small=true;
        bool is_upper=true;
        for(int i=1;i<word.size();i++)
        {
            if(isupper(word[i])==false)
            {
                is_upper=false;
            }
            if(islower(word[i])==false)
            {
                is_small=false;
            }
        }
        if(first==true && is_upper==true)
        {
            return true;
        }
        else if(first==true && is_small==true)
        {
            return true;
        }
        else if(first==false && is_small==true)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};