class Solution {
public:
    /*
        A A B A B B A
        0 1 2 3 4 5 6 
    */
    
    
    int help(char ch , string str , int k){
        int res = 0;
        int j=0,diff=0;
        for(int i=0;i<str.size();i++){
            if(str[i]!=ch) diff++;
            while(diff>k){
                if(str[j]!=ch) diff--;
                j++;
            }
            res=max(res,i-j+1);
        }
        return res;
    }
    int characterReplacement(string s, int k) {
        unordered_set<char>uniqueElements;
        for(auto key : s){
            uniqueElements.insert(key);
        }
        int res = 0;
        for(auto key : uniqueElements){
            int maxLen = help(key,s,k);
            //cout<<key<<" "<<maxLen<<endl;
            res = max(res,maxLen);
        }
        return res;
    }
};