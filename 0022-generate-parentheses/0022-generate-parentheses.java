class Solution {
    
    List<String> res = new ArrayList<>();
    
    
    public void help(int open , int close ,String path, int n){
        
        if(close == n && open == n){
            res.add(path);
            return ;
        }
        
        if(open > n || (close == n && open != n)){
            return ;
        }
        
        if(open >= close){
            
            help(open+1,close,path+'(',n);
            help(open,close+1,path+')',n);
        }
        else{
            help(open,close+1,path+')',n);
        }
        
    }
    
    public List<String> generateParenthesis(int n) {
        String path = new String();
        int open = 0;
        int close = 0;
        help(open,close,path,n);
        return res;
    }
}