class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int j = 0;
        int res = 0;
        unordered_map<char,int>m;
        for(int i=0;i<s.size();i++){
            char curr = s[i];
            m[curr]++;
            while(j<i && m[curr]>1){
                char temp = s[j];
                m[temp]--;
                j++;
            }
            res = max(res,i-j+1);
        }
        return res;
    }
};