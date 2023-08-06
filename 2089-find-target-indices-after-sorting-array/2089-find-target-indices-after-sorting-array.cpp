class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int fpos = -1;
        int lpos = -1;
        int low = 0;
        int high = nums.size()-1;
        
        while(low<=high){
            int mid = (low + high)/2;
            
            if(nums[mid] == target){
                fpos = mid;
                high = mid-1;
            }else if(nums[mid] < target){
                low = mid + 1;
            }else if(nums[mid] > target){
                high = mid - 1;
            }
        }
        
        low = 0;
        high = nums.size()-1;
        
        while(low<=high){
            int mid = (low + high)/2;
            
            if(nums[mid] == target){
                lpos = mid;
                low = mid + 1;
            }else if(nums[mid] < target){
                low = mid + 1;
            }else if(nums[mid] > target){
                high = mid - 1;
            }
        }
        if(lpos == -1 && fpos == -1){
            return {};
        }
        if(lpos == fpos){
            return {fpos};
        }
        vector<int>res;
        for(int i=fpos;i<=lpos;i++){
            res.push_back(i);
        }
        return res;
        
    }
};