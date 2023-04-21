class Solution {
    
    public static String sortString(String s) {
        char[] chars = s.toCharArray();
        Arrays.sort(chars);
        return new String(chars);
    }
    
    public List<List<String>> groupAnagrams(String[] strs) {
        
        
        HashMap<String, ArrayList<String>> map = new HashMap<>();
        
        for(String word : strs){
            
            String sorted = sortString(word);
            ArrayList<String> list= map.getOrDefault(sorted , new ArrayList<>());
            list.add(word);
            map.put(sorted,list);
        }
        
        List<List<String>>res = new ArrayList<>();
        
        for(String word : map.keySet()){
            ArrayList<String>anagrams = map.get(word);
            res.add(anagrams);
        }
        
        return res;

        
    }
}