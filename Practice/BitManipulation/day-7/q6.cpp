class Solution {
public:
  vector<int> xorQueries(vector<int> &a, vector<vector<int>> &q) {
    unordered_map<int, int> mp;
    mp[-1] = 0;
    int x = 0;
    for (int i = 0; i < a.size(); i++) {
      x ^= a[i];
      mp[i] = x;
    }
    int n = q.size();
    vector<int> ans(n);
    for (int i = 0; i < q.size(); i++) {
      int l, r;
      l = q[i][0], r = q[i][1];
      ans[i] = mp[r] ^ mp[l - 1];
    }

    return ans;
  }
};