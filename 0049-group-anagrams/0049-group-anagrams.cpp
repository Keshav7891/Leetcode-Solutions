class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,list<string>>m;
        for(auto key : strs)
        {
            string temp = key;
            sort(temp.begin(),temp.end());
            m[temp].push_back(key);
        }
        vector<vector<string>>res;
        for(auto key : m)
        {
            vector<string>temp;
            for(auto key1 : key.second)
            {
                temp.push_back(key1);
            }
            res.push_back(temp);
        }
        return res;
    }
};