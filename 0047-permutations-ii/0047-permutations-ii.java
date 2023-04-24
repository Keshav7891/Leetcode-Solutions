class Solution {
    
    List<List<Integer>> res = new ArrayList<>();
    HashSet<ArrayList<Integer>> s = new HashSet<>();
    
    public void help(ArrayList<Integer> path , boolean[] used , int[] nums){
        
        if(path.size() == nums.length){
            s.add(new ArrayList<>(path));
            return;
        }
        
        
        for(int i=0;i<nums.length;i++){
            
            if(used[i] == false){
                path.add(nums[i]);
                used[i] = true;
                help(path,used,nums);
                used[i] = false;
                path.remove(path.size()-1);
            }
            
        }
        
    }
    
    public List<List<Integer>> permuteUnique(int[] nums) {
        ArrayList<Integer> path = new ArrayList<>();
        boolean[] used = new boolean[nums.length];
        List<List<Integer>> res = new ArrayList<>();
        help(path,used,nums);
        
        for(ArrayList<Integer> ele : s){
            res.add(ele);
        }
        
        return res;
    }
}