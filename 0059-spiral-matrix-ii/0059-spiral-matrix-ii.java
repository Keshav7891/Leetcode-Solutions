class Solution {
    public int[][] generateMatrix(int n) {
        
        
        int [][] matrix = new int[n][n];
        int count = 0;
        
        int minr = 0;
        int minc = 0;
        int maxr = n-1;
        int maxc = n-1;
        
        int c = 1;
        
        while(c!=n*n + 1){
            
            
            for(int i=minc;i<=maxc && c<n*n + 1;i++){
                matrix[minc][i] = c;
                c++;
            }
            
            minr++;
            
            for(int i=minr;i<=maxr && c<n*n + 1;i++){
                matrix[i][maxc] = c;
                c++;
            }
            
            maxc--;
            
            for(int i=maxc;i>=minc && c<n*n + 1;i--){
                matrix[maxr][i] = c;
                c++;
            }
            
            maxr--;
            
            for(int i=maxr;i>=minr && c<n*n + 1;i--){
                matrix[i][minc] = c;
                c++;
            }
            
            minc++;
            
            
        }
        
        
        
        return matrix;
        
    }
}