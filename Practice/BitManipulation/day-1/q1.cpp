#include <iostream>
using namespace std;

#include <bits/stdc++.h>
#define lli long long int

// count set bits in an integer

int main() {
  int n;
  cin >> n;
  int cnt = 0;
  while (n != 0) {
    int rmbs = n & -n;
    n ^= rmbs;
    cnt++;
  }
  cout << cnt << "\n";
}
