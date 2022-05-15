class Solution {
public:
    const vector<string> keypad = {"", "", "abc", "def", "ghi", "jkl","mno", "pqrs", "tuv", "wxyz"};
vector<string>help(string str)
{
    if(str.size()==0)
    {
        vector<string>temp;
        temp.push_back("");
        return temp;
    }
    string comb = keypad[str[0]-'0'];
    vector<string>res = help(str.substr(1));
    vector<string>temp;
    for(auto ch : comb)
    {
        for(auto key : res)
        {
            temp.push_back(ch+key);
        }
    }
    return temp;
}
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits=="")
        {
            return res;
        }
        res = help(digits);
        return res;
    }
};