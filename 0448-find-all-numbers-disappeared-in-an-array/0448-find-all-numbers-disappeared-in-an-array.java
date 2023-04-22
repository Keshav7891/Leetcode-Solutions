class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        
        
        
        
        // 4  3  2  7  8  2  3  1
        // 0  1  2  3  4  5  6  7
        
        // 4  3  2  7  8  2  3  1
        // 0  1  2  3  4  5  6  7
        // -4 -3 -2 -7  8  2 -3 -1
        
        
        List<Integer> res = new ArrayList<>();
        
        for(int i=0;i<nums.length;i++){
            int index = Math.abs(nums[i]) - 1;
            if(nums[index] > 0){
                nums[index] = nums[index] * -1;
            }
        }
        
        for(int i=0;i<nums.length;i++){
            
            if(nums[i] > 0){
                res.add(i+1);
            }
        }
        
        return res;
        
        
        
    }
}