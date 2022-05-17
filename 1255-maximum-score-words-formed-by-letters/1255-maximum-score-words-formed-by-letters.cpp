class Solution {
public:
    int help(vector<string>&words , unordered_map<char,int>&freq, vector<int>&score , int index)
    {
        if(index == words.size())
        {
            return 0;
        }
        
        int not_picked = 0 + help(words,freq,score,index+1);
        int points = 0;
        bool isValid = true;
        string word = words[index];
        for(auto key : word)
        {
            if(freq[key]==0)
            {
                isValid = false;
            }
            freq[key]--;
            points = points + score[key-'a'];
        }
        int picked = 0;
        if(isValid == true)
        {
            picked = points + help(words,freq,score,index+1);
        }
        for(auto key : word)
        {
            freq[key]++;
        }
        return max(picked , not_picked);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score)
    {
        unordered_map<char,int>freq;
        for(auto key : letters)
        {
            freq[key]++;
        }
        int res = help(words,freq,score,0);
        return res;
    }
};