class Solution {
public:
  int cntBits(int n) {
    int cnt = 0;
    int msk = 1;
    for (int i = 0; i < 32; i++) {
      if ((msk & n) == 1)
        cnt++;
      n = (n >> 1);
    }
    return cnt;
  }
  int sumIndicesWithKSetBits(vector<int> &a, int k) {
    int s = 0;
    for (int i = 0; i < a.size(); i++) {
      int cnt = cntBits(i);
      if (cnt == k)
        s += a[i];
    }
    return s;
  }
};