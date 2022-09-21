class Solution {
public:
    int minFlips(string target) {
        int curr = 0;
        int res = 0;
        for(int i=0;i<target.size();i++)
        {
            //cout<<curr<<" "<<target[i]<<" "<<res<<endl;
            if(curr != target[i] - '0')
            {
                res++;
                curr = !curr;
            }
        }
        return res;
    }
};