class Solution {
public:
    int help(int index , int n , string vowels)
    {
        if(n == 0)
        {
            return 1;
        }
        if(index == vowels.size())
        {
            if(n == 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        
            
        int pick = help(index,n-1,vowels);
        int not_pick = help(index+1,n,vowels);
            
        return pick + not_pick;
        
    }
    int countVowelStrings(int n) {
        string vowels = "aeiou";
        int res = help(0,n,vowels);
        return res;
    }
};