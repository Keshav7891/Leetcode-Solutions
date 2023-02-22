class Solution {
public:
    vector<string>res;
    void help(int n , string path , int open , int close)
    {
        if(n==0)
        {
            //cout<<path<<" "<<open<<" "<<close<<endl;
            if(close == open)
            {
                res.push_back(path);
            }
            return;
        }
        if(close < open)
        {
            help(n-1,path+'(',open+1,close);
            help(n-1,path+')',open,close+1);
        }
        else if(close == open)
        {
            help(n-1,path + '(' , open+1,close);
        }
    }
    vector<string> generateParenthesis(int n) {
        n = 2 * n;
        help(n,"",0,0);
        return res;
    }
};