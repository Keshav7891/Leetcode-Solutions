class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sum = nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i] == nums[i-1]){
                continue;
            }else{
                sum = sum + nums[i];
            }
        }
        sum = sum * 2;
        for(auto key : nums){
            sum = sum - key;
        }
        return sum;
    }
};