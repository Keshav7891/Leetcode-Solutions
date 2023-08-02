class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        //[1,1,1,5,6,4]
        //[1,1,1,4,5,6]
        //[1,6,1,4,5,1]
        //[1,6,1,5,4,1]
        vector<int>res(nums.size(),-1);
        sort(nums.begin(),nums.end());
        int k = nums.size()-1;
        int i=1;
        while(i<nums.size()){
            res[i] = nums[k];
            k--;
            i = i+2;
        }
        for(int i=0;i<nums.size();i++){
            if(res[i]==-1){
                res[i] = nums[k];
                k--;
            }
        }
        nums = res;
        //return nums;
        
        
    }
};