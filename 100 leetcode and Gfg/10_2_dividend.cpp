//if only integer is to be found not precision answer
/*
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor){
            return 1;
        }

        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX; // Overflow case: -2^31 / -1 results in 2^31 - 1
        }

        long n = abs(dividend);
        long d = abs(divisor);

        bool sign = true;
        if(dividend >= 0 && divisor<= 0) sign = false;
        if(dividend <= 0 && divisor>= 0) sign = false;

        long quotient =0;

        while(n>=d){
            int cnt =0 ;
            while(n>= (d << (1<<(cnt+1)))){
                cnt++;
            }
            quotient += 1<<cnt;
            n -= d<<cnt;
        }

        if(quotient == 1<<31 && sign){
            return INT_MAX;
        }
        if(quotient == 1<<31 && !sign){
            return INT_MIN;
        }

        return sign ? quotient : -quotient;

    }
};
*/