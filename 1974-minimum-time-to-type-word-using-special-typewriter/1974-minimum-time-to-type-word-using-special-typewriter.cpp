class Solution 
{
public:
    int minTimeToType(const string& s) 
    {
        int steps = 0;
        
        char cur = 'a';
        for (const char& c : s)
        {
            int step = minStep(cur, c);
            cur = c;
            
            steps += (step + 1);
        }
        
        return steps;
    }
private:
    int minStep(char a, char b)
    {
        if (a > b)
            std::swap(a, b);
        
        return std::min(b - a, a - 'a' + 'z' - b + 1);
    }
};