class Solution {
public:
    void sortColors(vector<int>& nums) {
        int one = 0;
        int zero = 0;
        int two = nums.size()-1;
        while(one <= two){
            int curr = nums[one];
            if(curr == 2){
                swap(nums[two] , nums[one]);
                two--;
            }
            else if(curr == 1){
                one++;
            }
            else{
                swap(nums[zero],nums[one]);
                one++;
                zero++;
            }
        }
    }
};