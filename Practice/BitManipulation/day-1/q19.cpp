#include <iostream>
using namespace std;

#include <bits/stdc++.h>
#define lli long long int

// reverse a number in c++

int reverseBinary(int n) {
  string s = bitset<32>(n).to_string();
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '1') {
      s = s.substr(i);
      break;
    }
  }
  reverse(s.begin(), s.end());
  int ans = stoll(s, nullptr, 2);
  return ans;
}

int main() {
  int n;
  cin >> n;
  int ans = reverseBinary(n);
  cout << ans << "\n";
  return 0;
}
