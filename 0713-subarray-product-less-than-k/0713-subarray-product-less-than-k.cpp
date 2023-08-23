class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int prdct = 1;
        int j = 0;
        int res = 0;
        for(int i=0;i<nums.size();i++){
            prdct = prdct * nums[i];
            while(prdct >= k ){
                //cout<<i<<" "<<j<<endl;
                int temp = nums[j];
                //cout<<temp<<endl;
                prdct = prdct / temp;
                j++;
            }
            res = res + (i-j+1);
        }
        
        return res;
    }
};