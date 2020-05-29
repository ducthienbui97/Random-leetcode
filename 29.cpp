// Leetcode 29. Divide Two Integers
class Solution {
public:
    int divide(int dividend, int divisor) {
        long long n = abs(1ll*dividend);
        long long d = abs(1ll*divisor);
        long long ans = 0;
        long long t = 1;
        while((n >> 1) >= d){ 
            d<<=1;
            t<<=1;
        }
        
        while(d >= abs(1ll*divisor)){
            if(n >= d){
                n -= d;
                ans += t;
            }
            d >>=1;
            t >>=1;
        }
        if(dividend < 0)
            ans = -ans;
        if(divisor < 0)
            ans = -ans;
        return min(ans,1ll*INT_MAX);
    }
};
