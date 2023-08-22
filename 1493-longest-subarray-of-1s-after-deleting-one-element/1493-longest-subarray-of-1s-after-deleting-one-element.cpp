class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int count = 0;
        int res = 0;
        int j = 0;
        for(int i=0;i<nums.size();i++){
            int curr = nums[i];
            if(curr == 0){
                count++;
                while(j<i && count==2){
                    if(nums[j] == 0){
                        count = 1;
                    }
                    j++;
                }
            }
            res = max(res,i-j);
        }
        return res;
    }
};