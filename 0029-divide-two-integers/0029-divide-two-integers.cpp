class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor) return 1;
        long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);

        long long quotient = 0;

        bool sign = (dividend < 0) == (divisor < 0);

        while(n >= d){
            int cnt = 0;
            while(n >= (d << (cnt+1))) cnt++;
            quotient += 1LL << cnt;
            n -= (d << cnt); 
        }

        if(quotient == (1LL <<31) && sign) return INT_MAX;
        if(quotient == (1LL << 31) && !sign) return INT_MIN;

        return sign ? quotient : -quotient;
    }
};

/*
we are dividing.... by left shift we do x << k = x/2^k;

10 , 3

10 - 3 -3 -3 = 1
3 << 1 = 6

*/