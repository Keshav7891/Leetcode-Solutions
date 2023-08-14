class Solution {
public:
    /*
    0-> 01
    1-> 10
           0
      0          1
   0    1     1     0
  0 1  1 0   1 0   0 1
    
    
    n=4
    k=5
    if(n%2==0){
        n/2;
    }else{
        (n+1)/2;
    }
    */
    int res = -1;
    int help(int n , int k)
    {
        if(n==1){
            return 0;
        }
        
        int parent = help(n-1 , k/2 + k%2);
        
        if(parent == 0 && k%2 != 0){
            return 0;
        }else if(parent == 0 && k%2 == 0){
            return 1;
        }else if(parent == 1 && k%2 != 0){
            return 1;
        }else if(parent == 1 && k%2 == 0){
            return 0;
        }
        
        return -1;
        
        
    }
    int kthGrammar(int n, int k) {
        return help(n,k);
    }
};