class Solution {
public:
    int divide(int dividend, int divisor) {
        long div = labs(dividend), divs = labs(divisor), ans = 0; // get the absolute value
        int sign = min(dividend, divisor) < 0 && max(dividend, divisor) > 0 ? -1 : 1; // get the sign

        while(divs <= div) { // if divisor is less than dividend
            long tmp = divs, m = 1;
            while (tmp << 1 <= div) { // repeat the divisor till it is less than dividend
                tmp <<= 1; // left shift the divisor
                m <<= 1; // left shift the quotient
            }
            div -= tmp; // minuse the divisor
            ans += m; // plus the quotient
        }
        return sign * ans;
    }
};