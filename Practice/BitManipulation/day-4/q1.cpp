#include <iostream>
using namespace std;

#include <bits/stdc++.h>
#define lli long long int

class Solution {
public:
  bool isPrime(int n) {
    if (n == 1)
      return false;
    else if (n == 2 || n == 3)
      return true;
    else if (n % 2 == 0 || n % 3 == 0)
      return false;
    for (int i = 5; i * i <= n; i += 6) {
      if (n % i == 0 || n % (i + 2) == 0)
        return false;
    }
    return true;
  }

  int countPrimeSetBits(int left, int right) {
    int cnt = 0;
    for (int i = left; i <= right; i++) {
      int ok = __builtin_popcount(i);
      cnt += isPrime(ok);
    }
    return cnt;
  }
};

int main() {}
// time complexity = o(√n)
