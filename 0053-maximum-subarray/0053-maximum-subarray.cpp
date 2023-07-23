class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;
        int currSum = 0;
        int resStart = -1;
        int resEnd = -1;
        int start = -1;
        int end = -1;
        for(int i=0;i<nums.size();i++){
            int key = nums[i];
            if(currSum > 0){
                currSum = currSum + key;
                end = i;
            }
            else{
                currSum = key;
                start = i;
                end = i;
            }
            if(currSum > res){
                res = currSum;
                resStart = start;
                resEnd = end;
            }
        }
        for(int i=resStart;i<=resEnd;i++){
            cout<<nums[i]<<" ";
        }
        return res;
    }
};