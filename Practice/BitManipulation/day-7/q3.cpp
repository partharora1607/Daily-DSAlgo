class Solution {
public:
  int matrixScore(vector<vector<int>> &v) {
    int n = v.size(), m = v[0].size();
    auto changeCol = [&](int jj) {
      for (int i = 0; i < n; i++) {
        v[i][jj] = (v[i][jj] == 0) ? 1 : 0;
      }
    };
    auto changeRow = [&](int ii) {
      for (int j = 0; j < m; j++) {
        v[ii][j] = (v[ii][j] == 0) ? 1 : 0;
      }
    };
    for (int i = 0; i < n; i++) {
      if (v[i][0] == 0)
        changeRow(i);
    }
    for (int j = 1; j < m; j++) {
      int cnt = 0;
      for (int i = 0; i < n; i++) {
        if (v[i][j] == 1)
          cnt++;
      }
      if (2 * cnt < n)
        changeCol(j);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      string s = "";
      for (int j = 0; j < m; j++)
        s += (v[i][j] + '0');
      ans += stoi(s, nullptr, 2);
    }
    return ans;
  }
};