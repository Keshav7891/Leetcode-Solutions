class Solution {
public:
    bool halvesAreAlike(string s) {
        int count = 0;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        for(int i=0;i<s.size();i++)
        {
            char curr = s[i];
            if(i<s.size()/2)
            {
                if(curr == 'a' || curr == 'e' || curr == 'i' || curr == 'o' || curr == 'u')
                {
                    count++;
                }
            }
            else
            {
                if(curr == 'a' || curr == 'e' || curr == 'i' || curr == 'o' || curr == 'u')
                {
                    count--;
                }
            }
        }
        if(count == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};