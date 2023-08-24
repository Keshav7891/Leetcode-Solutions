class Solution {
public:
    int numOfSubarrays(vector<int>& nums, int k, int threshold) {
        int sum = 0;
        int j = 0;
        int res = 0;
        for(int i=0;i<k;i++){
            sum = sum + nums[i];
        }
        if(sum / k >= threshold){
            res++;
        }
        for(int i=k;i<nums.size();i++){
            sum = sum - nums[i-k];
            sum = sum + nums[i];
            if(sum / k >= threshold){
                res++;
            }
        }
        return res;
    }
};