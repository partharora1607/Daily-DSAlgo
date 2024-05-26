#include <iostream>
using namespace std;

#include <bits/stdc++.h>
#define lli long long int

//  no of set bits as that of 1

// o(n * 32) time complexity
// int setBits1(int n) {
//   int cnt = __builtin_popcount(n);
//   int ans = 0;
//   for (int i = 0; i < n; i++) {
//     int ok = __builtin_popcount(i);
//     if (ok == cnt)
//       ans++;
//   }
//   return ans;
// }

// 0(1) constant time complexity

// time complexity o(r)
int ncr(int n, int r) {
  double sum = 1;
  for (int i = 1; i <= r; i++)
    sum = sum * (n - r + i) / i;
  return (int)sum;
}

int setBits1(int n) {
  int cnt = 0, rr = 0;
  for (int i = 0; i < 32; i++) {
    int msk = (1 << i);
    if (n & msk) {
      rr++;
      int nn = i;
      cnt += ncr(nn, rr);
    }
  }
  return cnt;
}

int main() {

  int n;
  cin >> n;
  int cnt = setBits1(n);
  cout << cnt << "\n";
  return 0;
}
