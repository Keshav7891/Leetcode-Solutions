class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<int,int>m;
        int end = s.size()-1;
        int j = 0;
        int res = 0;
        for(int i=0;i<s.size();i++){
            char curr = s[i];
            m[curr]++;
            while(m['a'] >= 1 && m['b'] >= 1 && m['c'] >= 1){
                res = res + end- i + 1;
                char temp = s[j];
                m[temp]--;
                j++;
                if(m[temp]==0){
                    m.erase(temp);
                }
            }
        }
        return res;
    }
};