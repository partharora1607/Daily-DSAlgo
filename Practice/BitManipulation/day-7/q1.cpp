class Solution {
public:
  vector<int> getMaximumXor(vector<int> &a, int maximumBit) {
    int n = (int)a.size();
    vector<int> ans;
    int x = 0;
    for (int i = 0; i < a.size(); i++)
      x ^= a[i];
    for (int i = n - 1; i >= 0; i--) {
      int msk = (1 << maximumBit) - 1;
      msk = (msk ^ x);
      ans.push_back(msk);
      x ^= a[i];
    }
    return ans;
  }
};