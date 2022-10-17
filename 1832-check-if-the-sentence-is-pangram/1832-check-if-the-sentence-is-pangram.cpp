class Solution {
public:
    bool checkIfPangram(string sentence) 
    {
        set<char>arr;
        for(auto key : sentence)
        {
            arr.insert(key);
        }
        
        return arr.size()==26;
        
    }
};