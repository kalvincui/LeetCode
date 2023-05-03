class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == divisor){
            return 1;
        }
        int sign = 1;
        if (dividend < 0){
            sign *=-1;
        }
        if (divisor < 0){
            sign *= -1;
        }
        unsigned int ans = 0;
        unsigned int a = abs(dividend);
        unsigned int b = abs(divisor);
        while (a >= b){
            int q = 0;
            while (a > (b<<(1+q))){
                q++;
            }
            ans += 1 << q;
            a = a - (b<<q);
        }
        if (ans == (1<<31) && sign == 1){
            return INT_MAX;
        }
        return ans * sign;
    }
};
