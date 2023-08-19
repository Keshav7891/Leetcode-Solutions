class Solution {
public:
    vector<string> m = {"","" , "abc" , "def" , "ghi" , "jkl" , "mno" , "pqrs" , "tuv" , "wxyz"};
    vector<string> help(string digits){
        if(digits.size() == 0){
            vector<string>res;
            res.push_back("");
            return res;
        }
        
        char curr = digits[0];
        string rem = digits.substr(1);
        
        string alpha = m[curr-'0'];
        //cout<<curr<<" "<<alpha<<endl;
        vector<string>prevRes = help(rem);
        vector<string>res;
        
        for(auto key : alpha){
            for(auto key1 : prevRes){
                string str = key + key1;
                res.push_back(str);
            }
        }
        
        return res;
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0){
            return {};
        }
        vector<string> res= help(digits);
        return res;
    }
};