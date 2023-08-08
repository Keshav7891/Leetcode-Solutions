class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int curr = nums[i];
            int index = abs(nums[i]);
            if(nums[index] < 0){
                return abs(curr);
            }
            
            nums[index] = -nums[index];
        }
        
        return -1;
    }
};