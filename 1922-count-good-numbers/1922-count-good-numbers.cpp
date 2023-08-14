class Solution {
public:
    long long power(long long x, long long n){
        if(n == 0){
            return 1;
        }
        long long ans = power(x, n/2);
        ans *= ans;
        ans %= 1000000007;
        if(n%2==1){
            ans *= x;
            ans %= 1000000007;
        }
        return ans;
    }
    int countGoodNumbers(long long n) {
        long long numberOfOddPlaces = n / 2;
        long long numberOfEvenPlaces = n / 2 + n % 2;
        
        long long evenPow = static_cast<long long>(power(5, numberOfEvenPlaces)) % 1000000007;
        long long oddPow = static_cast<long long>(power(4, numberOfOddPlaces)) % 1000000007;
        
        return (evenPow * oddPow) % 1000000007;
    }
};
