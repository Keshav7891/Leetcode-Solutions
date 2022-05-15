class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) 
    {
        vector<string>res;
        string check = "";
        for(auto key : words)
        {
            string temp = key;
            sort(key.begin(),key.end());
            if(check != key)
            {
                res.push_back(temp);
                check = key;
            }
        }

        return res;
        
    }
};