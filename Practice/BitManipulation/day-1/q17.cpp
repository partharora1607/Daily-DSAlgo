#include <iostream>
using namespace std;

#include <bits/stdc++.h>
#define lli long long int

// sum all set bits in all n natural numbers in c++ efficiently.

int setBits(int n) {
  int s = 0;
  for (int i = 1; i < n; i++) {
    int set = __builtin_popcount(i);
    s += set;
  }
  return s;
}

int main() {
  int n;
  cin >> n;
  int cnt = setBits(n);
  cout << cnt << "\n";
  return 0;
}
