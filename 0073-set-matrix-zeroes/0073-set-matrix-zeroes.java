class Solution {
    public void setZeroes(int[][] matrix) {
        HashSet<Integer> r = new HashSet<>();
        HashSet<Integer> c = new HashSet<>();
        
        for(int i=0;i<matrix.length;i++){
            for(int j=0;j<matrix[0].length;j++){
                if(matrix[i][j] == 0){
                    r.add(i);
                    c.add(j);
                }
            }
        }
        
        for(int i=0;i<matrix.length;i++){
            for(int j=0;j<matrix[0].length;j++){
                if(r.contains(i) || c.contains(j)){
                    matrix[i][j] = 0;
                }
            }
        }
    }
}