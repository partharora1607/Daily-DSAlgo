// count set bits in an integer

#include <iostream>
using namespace std;

#include <bits/stdc++.h>
#define lli long long int

int count_set_bits(int n) {
  int cnt = 0;
  while (n != 0) {
    int rsbm = (n & -n);
    n -= rsbm;
    cnt++;
  }
  return cnt;
}

int main() {
  int n;
  cin >> n;
  int cnt = count_set_bits(n);
  cout << cnt << "\n";
  return 0;
}
