class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        long div = labs(dividend), divs = labs(divisor), ans = 0; // get the absolute value
        int sign = min(dividend, divisor) < 0 && max(dividend, divisor) > 0 ? -1 : 1; // get the sign

        while(divs <= div) { // if divisor is less than dividend
            long tmp = divs, m = 1;
            while (tmp << 1 <= div) { // repeat the multiplication till the divisor is less than the dividend
                tmp <<= 1; // left shift the divisor
                m <<= 1; // left shift the quotient
            }
            div -= tmp; // minuse the divisor
            ans += m; // plus the quotient
        }
        return sign * ans;
    }
};