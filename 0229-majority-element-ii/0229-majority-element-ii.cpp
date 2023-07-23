class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int majority1 = -1;
        int majority2 = -1;
        int count1 = 0;
        int count2 = 0;
        
        for(int i=0;i<nums.size();i++){
            int curr = nums[i];
            if(curr == majority1){
                count1++;
            }
            else if(curr == majority2){
                count2++;
            }
            else if(count1 == 0){
                majority1 = curr;
                count1 = 1;
            }
            else if(count2 == 0){
                majority2 = curr;
                count2 = 1;
            }
            else{
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;
        for(auto key : nums){
            if(key == majority1){
                count1++;
            }
            if(key == majority2){
                count2++;
            }
        }
        vector<int>res;
        if(majority1 == majority2 && count1 > nums.size()/2 && count2 > nums.size()/2){
            return {majority1};
        }
        if(count1 > nums.size()/3){
            res.push_back(majority1);
        }
        if(count2 > nums.size()/3){
            res.push_back(majority2);
        }
        return res;
    }
};