class Solution {
public:
    double myPow(double x, int n) {
      double result = 1;
      long long abs_n = abs(static_cast<long long>(n));
      while(abs_n > 0) { // != 0
        if(abs_n & 1) { // odd
            result *= x; // multiply result and x
        }
        abs_n >>= 1; // divide by 2
        x *= x; // multiply x and x if n is even
      }
      return n < 0 ? 1 / result : result;
    }
};