class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int>s;
        int res = 0;
        for(auto key : banned)
        {
            s.insert(key);
        }
        for(int i=1;i<=n;i++)
        {
            int curr = i;
            if(s.find(curr) != s.end())
            {
                continue;
            }
            if(maxSum-curr >= 0)
            {
                maxSum = maxSum - curr;
                res++;
            }
        }
        return res;
    }
};