class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        
        HashMap<Integer , Integer> m = new HashMap<>();
        
        for(int i=0;i<nums.length;i++){
            int freq = m.getOrDefault(nums[i],0);
            m.put(nums[i],freq+1);
        }
        
        PriorityQueue<Pair<Integer, Integer>> pq = new PriorityQueue<>((a,b)-> a.getKey() - b.getKey());
        
        
        for(Integer key : m.keySet()){
            int freq = m.get(key);
            pq.offer(new Pair<Integer,Integer>(freq,key));
            
            if(pq.size() > k){
                pq.poll();
            }
            
        }
        
        int []res = new int[k];
        int j=0;
        while(pq.size() != 0){
            Pair<Integer,Integer> top = pq.peek();
            res[j] = top.getValue();
            j++;
            pq.poll();
        }
        
        return res;
        
    }
}