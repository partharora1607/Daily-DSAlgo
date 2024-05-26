class Solution {
public:
  vector<bool> prefixesDivBy5(vector<int> &a) {
    int n = (int)a.size();
    vector<bool> res(n);
    int rem = 0;
    for (int i = 0; i < n; i++) {
      rem = (rem * 2) % 5;
      if (a[i] == 1)
        rem = (rem + 1) % 5;
      res[i] = (rem == 0);
    }
    return res;
  }
};