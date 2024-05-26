#include <iostream>
using namespace std;

#include <bits/stdc++.h>
#define lli long long int

// grey code in c++ using bit manipulation  by sumit malik

vector<vector<int>> helper(int n) {
  if (n == 1)
    return {{0}, {1}};
  vector<vector<int>> ans = helper(n - 1);
  vector<vector<int>> res;
  for (int i = 0; i < ans.size(); i++) {
    vector<int> v = ans[i];
    v.insert(v.begin(), 0);
    res.push_back(v);
  }
  for (int i = ans.size() - 1; i >= 0; i--) {
    vector<int> v = ans[i];
    v.insert(v.begin(), 1);
    res.push_back(v);
  }
  return res;
}

void greycode(int a) {
  vector<vector<int>> ans = helper(a);
  int n = ans.size(), m = ans[0].size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << ans[i][j] << " ";
    }
    cout << "\n";
  }
}

int main() {
  int n;
  cin >> n;
  greycode(n);
  return 0;
}
