class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1){
            return true;
        }
        int low = 1;
        int high = num-1;
        
        while(low <= high){
            long long int mid = (low + high)/2;
            long long prdct = mid * mid;
            if(prdct == num){
                return true;
            }else if(prdct > num){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        
        return false;
    }
};