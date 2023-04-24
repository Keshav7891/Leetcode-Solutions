class Solution {
    
    
    List<List<Integer>>res = new ArrayList<>();
    
    public void help(int index , int[] nums , ArrayList<Integer> path , int target){
        
        if(index == nums.length && target == 0){
            res.add(new ArrayList(path));
            return;
        }
        
        if(index >= nums.length || target < 0){
            return;
        }
        
        help(index+1,nums,path,target-0);
        
        if(target - nums[index] >= 0){
            path.add(nums[index]);
            help(index,nums,path,target-nums[index]);
            path.remove(path.size()-1);
        }
        
    }
    
    public List<List<Integer>> combinationSum(int[] nums, int target) {
        int index = 0;
        ArrayList<Integer> path = new ArrayList<>();
        help(index,nums,path,target);
        return res;
    }
}