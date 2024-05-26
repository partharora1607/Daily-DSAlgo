class Solution {
public:
  vector<vector<int>> subsets(vector<int> &a) {
    vector<vector<int>> res;
    int n = a.size();
    for (int i = 0; i < (1 << n); i++) {
      vector<int> v;
      for (int j = 0; j < n; j++) {
        int msk = (1 << j);
        if ((msk & i) != 0)
          v.push_back(a[j]);
      }
      res.push_back(v);
    }
    return res;
  }
};