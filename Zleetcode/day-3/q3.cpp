#include <iostream>
using namespace std;

#include <bits/stdc++.h>
#define lli long long int

// josephus problem

int josephus(int n) {
  // 2l+1
  int i = 1;
  while (i * 2 <= n) {
    i = i * 2;
  }
  n -= i;
  return 2 * n + 1;
}

int main() {
  int n;
  cin >> n;
  int ans = josephus(n);
  cout << ans << "\n";
  return 0;
}
