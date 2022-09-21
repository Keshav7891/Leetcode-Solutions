class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string ans = s;
        int n,i,k;
        n=s.size();
        for(i=0;i<n;i++)
        {
            ans[indices[i]]=s[i];
        }
        return ans;
    }
};