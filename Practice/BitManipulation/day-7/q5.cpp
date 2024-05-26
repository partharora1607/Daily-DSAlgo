class Solution {
public:
  int divide(int dividend, int divisor) {
    int sum = 0;
    int sign = 0;
    if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) {
      sign = 1;
    }
    dividend = abs(dividend);
    divisor = abs(divisor);
    while (dividend >= divisor) {
      int msk = divisor;
      int j = 0;
      while (msk <= dividend) {
        msk = (msk << 1);
        j++;
      }
      j--;
      msk = (msk >> 1);
      sum += (1 << j);
      dividend -= msk;
    }
    return sign == 0 ? sum : -sum;
  }
};