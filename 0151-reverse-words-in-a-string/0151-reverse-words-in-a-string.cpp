class Solution {
public:
    string reverseWords(string s) 
    {
        string res,sub;
        int i =0,j;
        int n = s.length();
        while(i<n)
        {
            while(i<n && s[i]==' ')
            {
                i++;
            }
            if(i>=n)
            {
                break;
            }
            j=i+1;
            while(j<n && s[j]!=' ')
            {
                j++;
            }
            sub = s.substr(i,j-i);
            if(res.length()==0)
            {
                res = sub;
            }
            else
            {
                res = sub + ' ' + res;
            }
            i=j+1;
        }
        return res;
        
    }
};