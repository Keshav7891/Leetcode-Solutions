class Solution {
    public boolean isIsomorphic(String s, String t) {
        
        
        if(s.length() != t.length()){
            return false;
        }
        
        HashMap <Character , Character> map = new HashMap<>();
        HashSet <Character> mapped = new HashSet<>();
        
        for(int i=0;i<s.length();i++){
            
            char ch1 = s.charAt(i);
            char ch2 = t.charAt(i);
            
            if(map.containsKey(ch1) == true){
                if(map.get(ch1) != ch2){
                    return false;
                }
            }else{
                map.put(ch1,ch2);
                if(mapped.contains(ch2)==true){
                    return false;
                }
                else
                {
                    mapped.add(ch2);   
                }
            }
        }
        
        return true;
        
    }
}