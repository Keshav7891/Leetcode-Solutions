class Solution {
    public int majorityElement(int[] nums) {
        int candid = nums[0];
        int freq = 0;
        
        for(int i=0;i<nums.length;i++){
            if(nums[i] == candid){
                freq++;
            }
            else{
                freq--;
                if(freq == 0){
                    freq = 1;
                    candid = nums[i];
                }
            }
        }
        
        int check=0;
        
        for(int i=0;i<nums.length;i++){
            if(nums[i] == candid){
                check++;
            }
        }
        
        if(check > nums.length/2){
            return candid;
        }
        
        return -1;
    }
}