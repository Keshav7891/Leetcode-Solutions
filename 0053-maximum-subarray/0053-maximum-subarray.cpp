class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;
        int currSum = 0;
        for(auto key : nums){
            if(currSum > 0){
                currSum = currSum + key;
            }
            else{
                currSum = key;
            }
            res = max(res,currSum);
        }
        return res;
    }
};