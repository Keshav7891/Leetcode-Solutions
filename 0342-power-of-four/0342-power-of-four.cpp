class Solution {
public:
    bool help(int n,long long int curr,int k){
        if(curr == n){
            return true;
        }else if(curr > n){
            return false;
        }
        
        return help(n,curr*k,k);
    }
    bool isPowerOfFour(int n) {
        int curr = 1;
        return help(n,curr,4);
    }
};