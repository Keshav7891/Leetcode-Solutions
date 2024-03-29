class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        int res = -1;
        while(low<=high){
            int mid = (low + high) >> 1;
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] < target){
                res = mid;
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return res+1;
    }
};