class Solution {
public:
    bool isLongPressedName(string name, string typed) 
    {
        int i=0;
        int j=0;
        while(i!=name.size() && j!=typed.size())
        {
            if(name[i]==typed[j])
            {
                i++;
                j++;
            }
            else
            {
                if(!j || typed[j-1]!=typed[j])
                {
                    return false;
                }
                j++;
            }
        }
        
        while(j!=typed.size())
        {
            if(typed[j-1]!=typed[j])
            {
                return false;
            }
            j++;
        }
        return i==name.size();
        
    }
};