class Solution {
public:
    int romanToInt(std::string s) {
        unordered_map<char, int> roman;
        roman['I'] = 1;
        roman['V'] = 5;
        roman['X'] = 10;
        roman['L'] = 50;
        roman['C'] = 100;
        roman['D'] = 500;
        roman['M'] = 1000;

        int result = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (i + 1 < s.length() && roman[s[i]] < roman[s[i+1]]) {
                result -= roman[s[i]];
            } 
            else {
                result += roman[s[i]];
            }
        }
        return result;
    }
};