class Solution {
    
    List<List<Integer>> res = new ArrayList<>();
    
    public void help(int index , int n , int k , ArrayList<Integer> path){
        
        if(k == 0){
            res.add(new ArrayList<Integer>(path));
            return;
        }
        
        
        for(int i = index;i<=n;i++){
            path.add(i);
            help(i+1,n,k-1,path);
            path.remove(path.size()-1);
        }
        
    }
    
    public List<List<Integer>> combine(int n, int k) {
        int index = 1;
        ArrayList<Integer>path = new ArrayList<>();
        help(index,n,k,path);
        
        return res;
    }
}