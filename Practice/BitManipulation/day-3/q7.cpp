#include <iostream>
using namespace std;

#include <bits/stdc++.h>
#define lli long long int

class Solution {
public:
  vector<int> evenOddBit(int n) {
    int even = 0, odd = 0;
    for (int i = 0; i < 32; i++) {
      int msk = (1 << i);
      if ((n & msk) != 0) {
        if ((i & 1))
          odd++;
        else
          even++;
      }
    }
    return {even, odd};
  }
};

int main() {}
