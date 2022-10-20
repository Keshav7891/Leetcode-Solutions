class Solution {
public:
    int lengthOfLastWord(string s) {
        int start = -1;
        int end = -1;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]!=' ')
            {
                end = i;
                break;
            }
        }
        for(int i=end;i>=0;i--)
        {
            if(s[i]==' ')
            {
                start = i;
                break;
            }
        }
        //cout<<start<<" "<<end<<endl;
        return end - start;
    }
};