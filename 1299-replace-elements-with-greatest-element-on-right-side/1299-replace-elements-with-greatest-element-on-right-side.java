class Solution {
    public int[] replaceElements(int[] arr) {
     
        int rplc = -1;
        int check = -1;
        
        for(int i=arr.length-1; i>=0;i--){
            if(check == -1){
                rplc = arr[i];
                arr[i] = -1;
                check = 1;
            }
            else{
                int temp = arr[i];
                arr[i] = rplc;
                if(rplc < temp){
                    rplc = temp;
                }
            }
        }
        
        return arr;
        
    }
}