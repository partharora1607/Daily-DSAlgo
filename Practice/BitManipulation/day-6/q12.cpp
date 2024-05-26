class Solution {
public:
  vector<int> getMaximumXor(vector<int> &a, int maximumBit) {
    int x = 0;
    for (int i = 0; i < a.size(); i++)
      x ^= a[i];
  }
};