class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>m;
        for(int i=0;i<s.size();i++)
        {
            m[s[i]]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto key : m)
        {
            pq.push(make_pair(key.second,key.first));
        }
        string str="";
        while(pq.empty()==false)
        {
            char ch = pq.top().second;
            int freq = pq.top().first;
            str+=string(freq,ch);
            pq.pop();
        }
        return str;
    }
};