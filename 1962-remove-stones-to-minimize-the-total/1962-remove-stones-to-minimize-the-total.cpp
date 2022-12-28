class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<double>pq;
        for(auto key : piles)
        {
            pq.push(key*1.0);
        }
        while(k--)
        {
            auto curr = pq.top();
            pq.pop();
            double temp = ceil(curr/2);
            //cout<<temp<<" "<<curr<<endl;
            pq.push(temp);
        }
        int res = 0;
        while(pq.empty()==false)
        {
            auto curr = pq.top();
            pq.pop();
            res = res + curr;
        }
        return res;
    }
};