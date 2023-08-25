class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int count = 0;
        for(auto key : nums){
            count = count + key;
        }
        
        int res = INT_MAX;
        int k = count;
        int zeroCount = 0;
        int oneCount = 0;
        
        for(int i=0;i<k;i++){
            int curr = nums[i];
            if(curr == 0)   zeroCount++;
            if(curr == 1)   oneCount++;
        }
        
        res = min(res,zeroCount);
        
        for(int i=k;i<nums.size();i++){
            int curr = nums[i];
            int temp = nums[i-k];
        
            if(curr == 0)   zeroCount++;
            if(curr == 1)   oneCount++;
            
            if(temp == 0)   zeroCount--;
            if(temp == 1)   oneCount--;
            
            res = min(res,zeroCount);
        }
        
        int leftWindow = k-1;
        int leftWindowZero = 0;
        int leftWindowOne = 0;
        
        int rightWindow = nums.size()-1;
        int rightWindowZero = 0;
        int rightWindowOne = 0;
        
        for(int i=0;i<=leftWindow;i++){
            int curr = nums[i];
            if(curr == 0)   leftWindowZero++;
            if(curr == 1)   leftWindowOne++;
        }
        
        
        
        int a = leftWindow;
        int b = nums.size()-1;
        res = min(res,leftWindowZero+rightWindowZero);
        //cout<<leftWindowZero<<" "<<rightWindowZero<<endl;
        for(int i=1;i<=count;i++){
            int curr1 = nums[leftWindow];
            if(curr1 == 0)  leftWindowZero--;
            if(curr1 == 1)  leftWindowOne--;
            leftWindow--;
            
            int curr2 = nums[rightWindow];
            if(curr2 == 0)  rightWindowZero++;
            if(curr2 == 1)  rightWindowOne++;
            rightWindow--;
            //cout<<leftWindowZero<<" "<<rightWindowZero<<endl;
            res = min(res,leftWindowZero+rightWindowZero);
        }
        
        
        
        return res;
        
        
    }
};