class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        m[0] = 1;
        int res = 0;
        int currSum = 0;
        for(int i=0;i<nums.size();i++){
            currSum = currSum + nums[i];
            int rem = currSum - k;
            if(m.find(rem)!=m.end()){
                res = res + m[rem];
            }
            m[currSum]++;
        }
        return res;
    }
};