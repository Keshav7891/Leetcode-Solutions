class Solution {
public:
    int findKthPositive(vector<int>& nums, int k) {
        
        int j = 0;
        for(int i=1;i<=1000;i++){
            if(j<nums.size() && nums[j] == i){
                j++;
            }else{
                k--;
                if(k==0){
                    return i;
                }
            }
        }
        
        return 1000 + k;
    }
};