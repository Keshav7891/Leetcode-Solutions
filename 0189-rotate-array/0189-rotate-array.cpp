class Solution {
public:
    // 1 2 3 4 5 6 7 
    // 1 2 3 4 7 6 5
    // 4 3 2 1 7 6 5
    // 5 6 7 1 2 3 4
    void help(vector<int>&nums , int low , int high)
    {
        while(low<=high)
        {
            swap(nums[low],nums[high]);
            low++;
            high--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        int pivot = nums.size()-k-1;
        help(nums,0,pivot);
        help(nums,pivot+1,nums.size()-1);
        help(nums,0,nums.size()-1);
    }
};