class Solution {
public:
    // 4 5 2 6 5 4
    //454256
    
    // find the point
    //swap it with min in right
    //
    int nextGreaterElement(int n) {
        long long res = 0;
        string nums = to_string(n);
        int j = nums.size()-1;
        while(j!=0){
            if(nums[j-1] < nums[j]){
                break;
            }
            j--;
        }
        if(j==0){
            return -1;
        }
        int pivotIndex = j-1;
        int pivotEle = nums[pivotIndex];
        int currIndex = -1;
        int currEle = INT_MAX;
        for(int i=nums.size()-1;i>pivotIndex;i--){
            if(nums[i] > pivotEle && nums[i] < currEle){
                currEle = nums[i];
                currIndex = i;
            }
        }
        swap(nums[pivotIndex],nums[currIndex]);
        sort(nums.begin()+pivotIndex+1,nums.end());
        res = stoll(nums);
        if (res > INT_MAX) {
            return -1;
        }
        return static_cast<int>(res);
    }
};