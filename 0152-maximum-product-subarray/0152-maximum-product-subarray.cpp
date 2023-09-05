class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prdct = 1;
        int res = INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(prdct == 0){
                prdct = nums[i];
            }else{
                prdct = prdct * nums[i];   
            }
            res = max(res,prdct);
        }
        prdct = 1;
        for(int i=nums.size()-1;i>=0;i--){
            if(prdct == 0){
                prdct = nums[i];
            }else{
                prdct = prdct * nums[i];   
            }
            res = max(res,prdct);
        }
        return res;
    }
};