class Solution {
public:
    bool wordPattern(string pattern, string str) {
        int i = 0;
        int n = pattern.size();
        unordered_map<char,int>m1;
        unordered_map<string,int>m2;
        string word;
        stringstream iss(str);
        while (iss >> word)
        {
            if(i==n || m1[pattern[i]]!=m2[word])
            {
                return false;
            }
            m1[pattern[i]] = m2[word] = i+1;
            i++;
        }
        return i==n;
    }
};