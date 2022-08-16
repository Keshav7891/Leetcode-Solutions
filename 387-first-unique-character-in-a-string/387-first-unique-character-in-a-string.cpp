class Solution {
public:
    const int CHAR=256;
    int firstUniqChar(string str) 
    {
        int fi[CHAR];
        fill(fi,fi+CHAR,-1);
        for(int i=0;i<str.length();i++)
        {
            if(fi[str[i]]==-1)
            {
                fi[str[i]]=i;
            }
            else 
            {
                fi[str[i]]=-2;
            }
        }
        int res=INT_MAX;
        for(int i=0;i<CHAR;i++)
        {
            if(fi[i]>=0)
            {
                res=min(res,fi[i]);
            }
        }
        if(res==INT_MAX)
        {
            return -1;
        }
        else
        {
            return res;
        }
        
    }
};