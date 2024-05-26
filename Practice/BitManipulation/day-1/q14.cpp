#include <iostream>
using namespace std;

#include <bits/stdc++.h>
#define lli long long int

unsigned int swapBits(unsigned int n) {
  // Your code here
  int omask = 0x55555555;
  int emask = 0xAAAAAAAA;

  int msk1, msk2;
  msk1 = (n & emask);
  msk2 = (n & omask);

  msk1 = (msk1 >> 1);
  msk2 = (msk2 << 1);

  return (msk1 | msk2);
}

int main() {
  int n;
  cin >> n;
  int ans = swapBits(n);
  cout << ans << "\n";
  return 0;
}
