class Solution {
public:
    int minimumCardPickup(vector<int>& nums) {
        unordered_map<int,int>m;
        int res = INT_MAX;
        for(int i=0;i<nums.size();i++){
            int curr = nums[i];
            if(m.find(curr)!=m.end()){
                res = min(res,i-m[curr]+1);
            }
            m[curr] = i;
        }
        if(res == INT_MAX){
            return -1;
        }
        return res;
    }
};