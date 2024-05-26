class Solution {
public:
  int singleNumber(vector<int> &a) {
    int xorr = 0;
    for (int i = 0; i < a.size(); i++)
      xorr ^= a[i];
    return xorr;
  }
};