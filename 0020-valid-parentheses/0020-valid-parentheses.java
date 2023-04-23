class Solution {
    
    public boolean check(Character ch , Character top){
        if(top == '[' && ch == ']' || top == '(' && ch == ')' || top == '{' && ch == '}' ){
            return true;
        }
        else{
            return false;
        }
    }
    
    public boolean isValid(String s) {
        
        
        Stack<Character> st = new Stack<>();
        
        for(int i=0;i<s.length();i++){
            char ch = s.charAt(i);
            
            
            if(st.empty() == true || (ch == '{' || ch == '('  || ch == '[' )){
                st.push(ch);
            }
            else{
                char top = st.peek();
                
                if( check(ch,top) == true){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
        
        if(st.size() != 0){
            return false;
        }
        
        return true;
        
    }
}