class Solution {
public:
    int longestBeautifulSubstring(string word) {
        vector<char>vowels = {'a','e','i','o','u'};
        int j = 0;
        int k = 0;
        int res = 0;
        char prev = '-';
        for(int i=0;i<word.size();i++){
            char ch = word[i];
            
            if(ch == 'a'){
                if(prev == 'a'){
                    continue;
                }else{
                    //cout<<"Reset"<<i<<endl;
                    prev = 'a';
                    j = i;
                    k = 1;
                }
            }else{
                if(k<5 && ch == vowels[k]){
                    prev = ch;
                    k++;
                }else if(ch != prev){
                    prev = ch;
                    k = 0;
                }
            }
            //cout<<k<<" ";
            if(k == vowels.size()){
                //cout<<i<<" "<<j<<endl;
                res = max(res,i-j+1);
            }
        }
        
        return res;
    }
};