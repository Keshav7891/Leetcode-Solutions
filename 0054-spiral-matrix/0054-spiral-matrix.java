class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        
        List<Integer>res = new ArrayList<>();
        
        int minr = 0;
        int minc = 0;
        int total = matrix.length * matrix[0].length;
        int maxr = matrix.length-1;
        int maxc = matrix[0].length-1;
        int c = 0;
        
        while(minr <= maxr && minc <= maxc){
            
            
            for(int i=minc;i<=maxc && c< total;i++){
                c++;
                res.add(matrix[minr][i]);
            }
            minr++;
            
            
            for(int i=minr;i<=maxr && c< total;i++){
                c++;
                res.add(matrix[i][maxc]);
            }
            maxc--;
            
            for(int i=maxc;i>=minc && c< total;i--){
                c++;
                res.add(matrix[maxr][i]);
            }
            maxr--;
            
            
            for(int i=maxr;i>=minr && c< total;i--){
                c++;
                res.add(matrix[i][minc]);
            }
            minc++;
             
        }
        
        return res;
        
    }
}