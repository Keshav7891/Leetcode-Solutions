class Solution {
public:
   vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
       sort(nums.begin(), nums.end());
       vector<int> preSum = {0};
       for(int num : nums) preSum.push_back(preSum[preSum.size()-1] + num);
       vector<int> res;
       for(int query : queries){
           int index = upper_bound(preSum.begin(), preSum.end(), query) - preSum.begin();
           res.push_back(index - 1);
       }
       return res;
   }
};