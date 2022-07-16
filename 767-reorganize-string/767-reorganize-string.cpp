class Solution {
public:
    string reorganizeString(string s)
    {
        map<char,int>m;
        string res = "";
        for(auto key : s)
        {
            m[key]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto key : m)
        {
            char ch = key.first;
            int freq = key.second;
            pq.push({freq,ch});
        }
            
        while(pq.size()>1)
        {
            auto top1 = pq.top();
            pq.pop();
            auto top2 = pq.top();
            pq.pop();
            
            res=res+top1.second+top2.second;
            
            top1.first = top1.first - 1;
            top2.first = top2.first - 1;
            
            if(top1.first>0)
            {
                pq.push(top1);
            }
            if(top2.first>0)
            {
                pq.push(top2);
            }
        }
        
        if(pq.empty()==false)
        {
            if(pq.top().first>1)
            {
                return "";
            }
            else
            {
                res=res+pq.top().second;
                pq.pop();
            }
        }
        return res;
    }
};