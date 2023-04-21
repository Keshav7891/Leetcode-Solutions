class Solution {
    public int[] twoSum(int[] nums, int target) {
        
        int res[] = new int[2];
        
        HashMap<Integer,Integer> m = new HashMap<>();
        
        for(int i=0;i<nums.length;i++){
            
            int rem = target - nums[i];
            
            if(m.containsKey(rem) == true){
                res[0] = i;
                res[1] = m.get(rem);
            }
            else{
                m.put(nums[i],i);
            }
            
        }
        
        
        
        
        return res;
    }
}