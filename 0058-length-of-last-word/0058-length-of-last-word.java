class Solution {
    public int lengthOfLastWord(String s) {
        
        int i = s.length()-1;
        
        while(s.charAt(i) == ' ')
        {
            i--;
        }
        
        int end = i;
        
        while(i!=-1 && s.charAt(i) != ' '){
            i--;
        }
        
        int start = i;
        
        return end - start;
    }
}