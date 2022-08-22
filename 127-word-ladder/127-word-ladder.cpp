class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>s;
        
        for(auto key : wordList)
        {
            s.insert(key);
        }
        
        queue<string>q;
        q.push(beginWord);
        
        int cost = 1;
        while(q.empty()==false)
        {
            int size = q.size();
            
            for(int i=0;i<size;i++)
            {
                auto curr = q.front();
                q.pop();
                
                if(curr == endWord)
                {
                    return cost;
                }
                
                for(int j=0;j<curr.size();j++)
                {
                    string temp = curr;
                    for(char ch='a';ch<='z';ch++)
                    {
                        temp[j] = ch;
                        if(temp==curr)
                        {
                            continue;
                        }
                        else if(s.find(temp)!=s.end())
                        {
                            q.push(temp);
                            s.erase(temp);
                        }
                    }
                }
            }
            cost++;
        }
        return 0;
    }
};