#include <iostream>
using namespace std;

#include <bits/stdc++.h>
#define lli long long int

void helper(vector<int> &a, int idx, vector<int> &curr,
            vector<vector<int>> &res) {
  if (idx == a.size()) {
    if (curr.size() > 0)
      res.push_back(curr);
    return;
  }
  curr.push_back(a[idx]);
  helper(a, idx + 1, curr, res);
  curr.pop_back();
  helper(a, idx + 1, curr, res);
}

vector<vector<int>> generateSubsequence(vector<int> &a) {
  vector<vector<int>> res;
  vector<int> curr;
  helper(a, 0, curr, res);
  return res;
}

int main() {
  vector<int> a = {1, 2, 3};
  vector<vector<int>> res = generateSubsequence(a);
  for (auto v : res) {
    for (auto e : v) {
      cout << e << " ";
    }
    cout << "\n";
  }
  return 0;
}
