class Solution {
public:
    string reverseVowels(string s) {
        int i = 0;
        int j = s.size()-1;
        bool flag1 = false, flag2 = false;
        while(i<j){
            char key1 = s[i];
            char key2 = s[j];
            
            if(key1 == 'a' || key1 == 'e' || key1 == 'i' || key1 == 'o' || key1 ==  'u' || key1 == 'A' || key1 == 'E' || key1 == 'I' || key1 == 'O' || key1 ==  'U'){
                flag1 = true;
                
            }else{
                i++;
            }
            
            if(key2 == 'a' || key2 == 'e' || key2 == 'i' || key2 == 'o' || key2 ==  'u' || key2 == 'A' || key2 == 'E' || key2 == 'I' || key2 == 'O' || key2 ==  'U'){
                flag2 = true;
            }else{
                j--;
            }
            
            if(flag1 == true && flag2 == true){
                //cout<<i<<" "<<j<<endl;
                swap(s[i],s[j]);
                flag1 = false;
                flag2 = false;
                i++;
                j--;
            }
        }
        return s;
    }
};