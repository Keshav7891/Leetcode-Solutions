class Solution {
public:
    int mySqrt(int x) {
        if(x<=1)
        {
            return x;
        }
        long long int low = 1;
        long long int high = x;
        long long int res = -1;
        long long int target = x * 1.0;
        while(low<=high){
            long long int mid = ((low + high)/2)*1.0;
            if(mid * mid == target){
                res = mid;
                break;
            }else if(mid * mid > target){
                high = mid - 1;
            }else{
                res = mid;
                low = mid + 1;
            }
        }
        cout<<res<<" "<<endl;
        return (int)res;
    }
};