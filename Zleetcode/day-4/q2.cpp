
#include <iostream>
using namespace std;

#include <bits/stdc++.h>
#define lli long long int

// all numbers repeating except 2

vector<int> solve(vector<int> &a) {
  int x = 0;
  for (auto e : a)
    x ^= e;
  int rsbm = (x & -x);
  vector<int> v1, v2;
  for (int i = 0; i < a.size(); i++) {
    if (a[i] & rsbm)
      v1.push_back(a[i]);
    else
      v2.push_back(a[i]);
  }
  int val1 = 0, val2 = 0;
  for (auto e : v1) {
    val1 ^= e;
  }
  for (auto e : v2) {
    val2 ^= e;
  }
  return val1 < val2 ? vector<int>{val1, val2} : vector<int>{val2, val1};
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  vector<int> ans = solve(a);
  cout << ans[0] << " " << ans[1] << endl;
  return 0;
}
