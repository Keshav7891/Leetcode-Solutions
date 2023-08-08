class Solution {
public:
    bool help(int n,long long int curr){
        if(curr == n){
            return true;
        }else if(curr > n){
            return false;
        }
        
        return help(n,curr*2);
    }
    bool isPowerOfTwo(int n) {
        long long int curr = 1;
        return help(n,curr);
    }
};