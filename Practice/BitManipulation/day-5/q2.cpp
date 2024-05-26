class Solution {
public:
  char findTheDifference(string s, string t) {
    int xorr = 0;
    for (int i = 0; i < s.size(); i++) {
      int ok = s[i] - 'a';
      int msk = (1 << ok);
      xorr ^= msk;
    }
    for (int i = 0; i < t.size(); i++) {
      int ok = t[i] - 'a';
      int msk = (1 << ok);
      xorr ^= msk;
    }
    for (int i = 0; i < 32; i++) {
      int msk = (1 << i);
      if (msk == xorr) {
        return i + 'a';
      }
    }
    return 'a';
  }
};