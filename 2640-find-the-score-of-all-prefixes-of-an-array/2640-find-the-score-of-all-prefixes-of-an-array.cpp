class Solution {
public:
    
    //2 -> 2 + 2 = 4 -> 4
    //2,3 -> 3 + 3 = 6 -> 10
    //2,3,7 -> 7 + 7 = 14 -> 24
    //2,3,7,5 -> 5 + 7 = 12 -> 36
    //2,3,7,5,10 -> 10 + 10 = 20 -> 56
    
    
    vector<long long> findPrefixScore(vector<int>& nums) {
        vector<int>temp = nums;
        for(int i=1;i<temp.size();i++){
            temp[i] = max(temp[i],temp[i-1]);
        }
        vector<long long>res;
        res.push_back(temp[0] + nums[0]);
        for(int i=1;i<nums.size();i++){
            
            res.push_back(nums[i] + temp[i] + res[i-1]);   
        }
        return res;
    }
};