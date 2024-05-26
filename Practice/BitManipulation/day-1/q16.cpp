#include <iostream>
using namespace std;

#include <bits/stdc++.h>
#define lli long long int

bool isMultipleOf3(string s) {
  int mske = 0xAAAAAAAA;
  int msko = 0x55555555;
  int m1, m2;
  m1 = (stoi(s) & mske);
  m2 = (stoi(s) & msko);
  int cnt1 = __builtin_popcount(m1), cnt2 = __builtin_popcount(m2);
  if ((cnt1 - cnt2) % 11 == 0)
    return true;
  else
    return false;
}

int main() {
  string s;
  cin >> s;
  bool ans = isMultipleOf3(s);
  cout << ((ans == true) ? "Yes" : "No") << "\n";
  return 0;
}
