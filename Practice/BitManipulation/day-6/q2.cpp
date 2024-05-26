#include <iostream>
using namespace std;

#include <bits/stdc++.h>
#define lli long long int

class Solution {
public:
  bool isPowerOfFour(int n) {
    int setBits = __builtin_popcount(n);
    if (setBits != 1)
      return false;
    int msk = 1, cnt = 0;
    for (int i = 0; i < 32; i++) {
      int msk = (1 << i);
      if ((msk & 1) == 0)
        cnt++;
      else
        break;
    }
    return cnt % 2 == 0;
  }
};

int main() {
  int a = -2147483648;
  string s = bitset<32>(a).to_string();
  int cnt = count(s.begin(), s.end(), '0');
  cout << s << "\n";
  cout << cnt << "\n";
}
