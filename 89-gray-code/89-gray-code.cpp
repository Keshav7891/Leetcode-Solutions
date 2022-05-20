class Solution {
public:
    vector<string> solve(int n)
    {
        if(n==1)
        {
            return {"0","1"};
        }
    
        vector<string>ans=solve(n-1);
        vector<string> mainAns;
        
        for(int i=0;i<ans.size();i++)
        {
            string s=ans[i];
            mainAns.push_back("0"+s);
        }
        for(int i=ans.size()-1;i>=0;i--)
        {
            string s=ans[i];
            mainAns.push_back("1"+s);
        }
        return mainAns;
     }
    vector<int> grayCode(int n) 
    {
        vector<string> strRes = solve(n);
        vector<int> result;
        for(int i=0;i<strRes.size();i++)
        {
            int val = stoi(strRes[i], 0, 2);
            result.push_back(val);
        }
        return result;
    }
        
};