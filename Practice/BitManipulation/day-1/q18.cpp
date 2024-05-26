#include <iostream>
using namespace std;

#include <bits/stdc++.h>
#define lli long long int

// time complexity o(r)
int ncr(int n, int r) {
  double sum = 1;
  for (int i = 1; i <= r; i++)
    sum = sum * (n - r + i) / i;
  return (int)sum;
}

int setBits(int n) {
  int ans = 0, cnt = 0;
  for (int i = 30; i >= 0; i--) {
    int msk = (1 << i);
    if ((n & msk) != 0) {
      int sans = 0;
      for (int j = 1; j <= i; j++) {
        int val = ncr(i, j);
        sans += val * j;
      }
      // cout << "ok" << (cnt * ttl) << "\n";
      sans += cnt * ((1 << i));
      ans += sans;
      cnt++;
    }
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  int cnt = setBits(n);
  cout << cnt << "\n";
  return 0;
}
