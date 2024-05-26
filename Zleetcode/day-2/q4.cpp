class Solution {
public:
  bool find132pattern(vector<int> &a) {
    int n = a.size();
    // store index
    vector<pair<int, int>> v(n);
    int mini = INT_MAX, maxi = INT_MIN;
    int mini_idx = -1, maxi_idx = -1;
    int f = 0;
    for (int i = 0; i < a.size(); i++) {
      if (f == 0) {
        if (a[i] < mini) {
          mini = a[i];
          mini_idx = i;
        }
      }
      if (a[i] > maxi) {
        maxi = a[i];
        maxi_idx = i;
      }
      v[i] = {mini_idx, maxi_idx};
      if (maxi_idx > mini_idx)
        f = 1;
    }

    for (int i = n - 1; i > 1; i--) {
      int mini = v[i - 1].first, maxi = v[i - 1].second;
      //   cout << mini << " " << maxi << endl;
      if (mini < maxi && a[i] > a[mini] && a[i] < a[maxi])
        return true;
    }

    return false;
  }
};