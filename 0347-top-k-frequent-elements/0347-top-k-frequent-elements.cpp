class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        for(auto key : nums)
        {
            m[key]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(auto &key : m)
        {
            pq.push({key.second,key.first});
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
        vector<int>res;
        while(pq.empty()==false)
        {
            auto curr = pq.top();
            pq.pop();
            res.push_back(curr.second);
        }
        return res;
    }
};