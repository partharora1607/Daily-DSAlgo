// iterative way to find the subsequence

#include <iostream>
using namespace std;

#include <bits/stdc++.h>
#define lli long long int

vector<vector<int>> generateSubsequenceIteratively(vector<int> &a) {
  vector<vector<int>> res;
  int n = a.size();
  for (int mask = 0; mask < (1 << n); mask++) {
    vector<int> sub;
    for (int i = 0; i < n; i++) {
      if ((mask >> i) & 1 == 1)
        sub.push_back(a[i]);
    }
    res.push_back(sub);
  }
  return res;
}

int main() {
  vector<int> v = {1, 2, 3};
  cout << "Iterative approach"
       << "\n";
  vector<vector<int>> ans = generateSubsequenceIteratively(v);
  for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < ans[i].size(); j++) {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
