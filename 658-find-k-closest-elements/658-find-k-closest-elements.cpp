class Solution {
public:
    vector<int> findClosestElements(vector<int>& nums, int k, int x) {
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        for(auto key : nums)
        {
            int diff = abs(key-x);
            pq.push(make_pair(diff,key));
        }
        vector<int>res;
        for(int i=0;i<k;i++)
        {
            auto top = pq.top();
            pq.pop();
            res.push_back(top.second);
        }
        sort(res.begin(),res.end());
        return res;
        
    }
};