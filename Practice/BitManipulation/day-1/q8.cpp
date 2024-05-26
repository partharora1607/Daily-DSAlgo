#include <iostream>
using namespace std;

#include <bits/stdc++.h>
#define lli long long int

lli steps(lli n) {
  if (n == 1)
    return 0;
  else if (n == 2)
    return 1;
  else if (n == 3)
    return 2;
  lli cnt = 0;
  while (n != 1) {
    cnt++;
    if (n == 3) {
      cnt++;
      break;
    }
    if ((n & 3) == 0) {
      n /= 2;
    } else if ((n & 3) == 1) {
      n--;
    } else if ((n & 3) == 2) {
      n /= 2;
    } else {
      n++;
    }
  }
  return cnt;
}

int main() {
  lli n;
  cin >> n;
  lli ans = steps(n);
  cout << ans << " ";
  return 0;
}
