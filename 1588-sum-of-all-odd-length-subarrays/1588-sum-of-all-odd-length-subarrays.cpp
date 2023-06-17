class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& nums) {
        int res = 0;
        for(int i=0;i<nums.size();i++){
            for(int j=i;j<nums.size();j++){
                if((i-j)%2==0){
                    int sum = 0;
                    for(int k=i;k<=j;k++){
                        res = res + nums[k];
                    }
                }
            }
        }
        return res;
    }
};