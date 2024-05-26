class Solution {
public:
  int countMaxOrSubsets(vector<int> &a) {
    int maxi = 0;
    int n = (int)a.size();
    for (int i = 0; i < a.size(); i++) {
      maxi |= a[i];
    }
    int cnt = 0;
    for (int i = 1; i < (1 << n); i++) {
      int orr = 0;
      for (int j = 0; j < n; j++) {
        int msk = (1 << j);
        if ((i & msk) != 0)
          orr |= a[j];
      }
      if (orr == maxi)
        cnt++;
    }
    return cnt;
  }
};