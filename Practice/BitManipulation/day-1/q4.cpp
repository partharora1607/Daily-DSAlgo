#include <iostream>
using namespace std;

#include <bits/stdc++.h>
#define lli long long int

vector<int> ok(vector<int> &a) {
  int xor1 = 0, xor2 = 0;
  for (int i = 0; i < a.size(); i++) {
    if ((a[i] & 1))
      xor1 ^= a[i];
    else
      xor2 ^= a[i];
  }
  return {xor1, xor2};
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  vector<int> ans = ok(a);
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";
  return 0;
}
