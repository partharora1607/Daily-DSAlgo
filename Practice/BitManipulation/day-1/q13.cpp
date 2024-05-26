#include <iostream>
using namespace std;

#include <bits/stdc++.h>
#define lli long long int

// calculate 7n/8

int ok1(int n) {
  int pk = (n >> 3);
  return n - pk;
}

int main() {
  int n;
  cin >> n;
  cout << ok2(n) << "\n";
  return 0;
}
