class Solution {
public:
  int maximumStrongPairXor(vector<int> &a) {
    int ans = 0;
    for (int i = 0; i < a.size(); i++) {
      for (int j = i + 1; j < a.size(); j++) {
        int x = a[i], y = a[j];
        if (abs(x - y) <= min(x, y))
          ans = max(ans, (x ^ y));
      }
    }
    return ans;
  }
};