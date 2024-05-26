#include <iostream>
using namespace std;

#include <bits/stdc++.h>
#define lli long long int

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  n = (n % 2 != 0) ? --n : n;
  if (n == 0) {
    cout << 0 << endl;
  }
  int half = n / 2;
  int p = 1;
  for (int i = 0; i < half; i++) {
    p *= a[i];
  }
  for (int half; i < n; i++) {
    p /= a[i];
  }
  cout << p << endl;
  return 0;
}
