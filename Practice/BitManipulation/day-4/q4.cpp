class Solution {
public:
  int binaryGap(int n) {
    int ans = 0;
    int p = -1;
    for (int i = 0; i < 32; i++) {
      int msk = (1 << i);
      if (msk & n) {
        if (p != -1)
          ans = max(ans, abs(i - p));
        p = i;
      }
    }
    return ans;
  }
};