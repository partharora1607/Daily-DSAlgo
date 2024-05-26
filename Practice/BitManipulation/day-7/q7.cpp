class Solution {
public:
  int minFlips(int a, int b, int c) {
    int cnt = 0;
    for (int i = 0; i < 32; i++) {
      int msk = (1 << i);
      if ((msk & c) != 0) {
        if ((msk & a) == 0 && (msk & b) == 0) {
          cnt++;
        }
      } else {
        if ((msk & a) != 0)
          cnt++;
        if ((msk & b) != 0)
          cnt++;
      }
    }
    return cnt;
  }
};