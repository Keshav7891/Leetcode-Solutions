class Solution {
public:
    // [4,3,2,-1]
    // [3,2,1,-1]
    // [1,1,-1,-2]
    // [-1,-1,-2,-3]
    int help(vector<int>nums){
        int low = 0;
        int high = nums.size()-1;
        int index = -1;
        while(low<=high){
            int mid = (low + high)/2;
            if(nums[mid] < 0){
                index = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        if(index == -1){
            return 0;
        }
        //cout<<index<<" ";
        return nums.size()-index;
    }
    int countNegatives(vector<vector<int>>& grid) {
        int res = 0;
        for(int i=0;i<grid.size();i++){
            int count =  help(grid[i]);
            res = res + count;
            //cout<<count<<endl;
        }
        return res;
    }
};