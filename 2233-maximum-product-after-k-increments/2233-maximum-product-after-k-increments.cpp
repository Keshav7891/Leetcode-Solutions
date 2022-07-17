class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<long long int,vector<long long int>,greater<long long int>>pq;
        for(auto key : nums)
        {
            pq.push(key);
        }
        while(k!=0)
        {
            long long int curr = pq.top();
            pq.pop();
            curr=curr+1;
            pq.push(curr);
            k--;
        }
        long long int res = 1;
        while(pq.empty()==false)
        {
            int curr = pq.top();
            res = (res * curr)%1000000007;
            pq.pop();
        }
        return res;
            
    }
};