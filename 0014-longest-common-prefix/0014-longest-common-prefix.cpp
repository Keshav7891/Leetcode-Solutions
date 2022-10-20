class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int res = strs[0].size();
        string base = strs[0];
        for(int i=1;i<strs.size();i++)
        {
            string curr = strs[i];
            int index = 0;
            int n = curr.size();
            int len = min(res,n);
            for(int k=0; k<len ;k++)
            {
                if(curr[k] == base[k])
                {
                    index++;
                }
                else
                {
                    break;
                }
            }
            res = index;
        }
        string ans = base.substr(0,res);
        return ans;
    }
};