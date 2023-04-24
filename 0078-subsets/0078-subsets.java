class Solution {
    
    List<List<Integer>>res = new ArrayList<>();
    
    public void help(int index , int[] nums , ArrayList<Integer>path){
        
        if(index == nums.length){
            res.add(new ArrayList<>(path));
            return;
        }
        
        
        path.add(nums[index]);
        help(index+1,nums,path);
        path.remove(path.size() - 1);
        help(index+1,nums,path);
    }
    
    
    public List<List<Integer>> subsets(int[] nums) {
        int index = 0;
        ArrayList<Integer> path = new ArrayList<>();
        help(index,nums,path);
        return res;
        
    }
}