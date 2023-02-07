class Solution {
public:
    /*
    1->1
    2->3
    3->6
    4->10
    5->15
    */
    int arrangeCoins(int n) {
        long long int low = 1;
        long long int high = n;
        while(low <= high)
        {
            long long int mid = low + (high - low) / 2;
            long long int needded_coins = (mid * (mid+1))/2;
            
            if( n == needded_coins)
            {
                return mid;
            }
            
            if(n > needded_coins)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return high;
    }  
};