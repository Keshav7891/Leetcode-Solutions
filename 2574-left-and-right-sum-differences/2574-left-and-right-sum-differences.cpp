class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int rsum = 0;
        for(auto key : nums){
            rsum = rsum + key;
        }
        rsum = rsum - nums[0];
        int lsum = nums[0];
        vector<int>res;
        res.push_back(rsum);
        for(int i=1;i<nums.size();i++){
            rsum = rsum - nums[i];
            int sum = abs(rsum - lsum);
            res.push_back(sum);
            lsum = lsum + nums[i];
        }
        return res;
    }
};