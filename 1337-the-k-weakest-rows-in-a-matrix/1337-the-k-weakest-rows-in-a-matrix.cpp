class Solution {
public:
    
struct cmp {
    bool operator()(pair<int,int> const& p1, pair<int,int> const& p2)
    {
        if(p1.first<p2.first){
            return true;
        }
        else if(p1.first==p2.first && p1.second<p2.second){
            return true;
        }
        return false;
    }
};

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>,cmp> pq;

        for(int i=0;i<mat.size();i++){
            vector<int>nums = mat[i];
            int index = -1;
            int low = 0;
            int high = nums.size()-1;
            
            while(low<=high){
                int mid = (low+high)/2;
                if(nums[mid] == 1){
                    index = mid;
                    low = mid + 1;
                }else{
                    high = mid - 1;
                }
            }
            int count;
            if(index == -1){
                count = 0;
            }else{
                count = index + 1;
            }
            
            pq.push({count,i});
            if(pq.size() > k){
                pq.pop();
            }
        }
        vector<int>res;
        while(pq.empty()==false){
            auto curr = pq.top().second;
            res.push_back(curr);
            pq.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};