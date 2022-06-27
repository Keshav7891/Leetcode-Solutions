class Solution {
public:
    int minPartitions(string str) {
        int res = 0;
        for(auto key : str)
        {
            int num = key - '0';
            res = max(res,num);
        }
        return res;
    }
};