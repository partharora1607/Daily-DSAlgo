class Solution {
public:
  int numberOfSteps(int n) {
    int cnt = 0;
    while (n) {
      cnt++;
      if ((n & 1) == 0) {
        n = (n >> 1);
      } else {
        n--;
      }
    }
    return cnt;
  }
};