class Solution {
public:
    //[3,1,2,9,6,4,1]
    //[3,1,4,2,6,9]
    void nextPermutation(vector<int>& nums) {
        if(nums.size()==1) return;
        int i = nums.size()-2;
        int j = nums.size()-1;
        while(i>=0 && nums[i]>=nums[i+1]) i--;
        if(i>=0){
            while(j>=0 && nums[j]<=nums[i]) j--;
            if(j>=0) swap(nums[i],nums[j]);
        }
        reverse(nums.begin()+i+1, nums.end());
    }
};
