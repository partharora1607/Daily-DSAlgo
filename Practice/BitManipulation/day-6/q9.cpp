class Solution {
public:
  int maximumXOR(vector<int> &a) {
    int ans = 0, n = a.size();
    for (int i = 0; i < 32; i++) {
      int msk = (1 << i);
      for (int j = 0; j < n; j++) {
        if ((a[j] & msk) != 0) {
          ans |= msk;
          break;
        }
      }
    }
    return ans;
  }
};