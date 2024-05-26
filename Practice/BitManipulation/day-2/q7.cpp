#include <iostream>
using namespace std;

#include <bits/stdc++.h>
#define lli long long int

class Solution {
public:
  int subsetXORSum(vector<int> &a) {
    int n = a.size();
    int s = 0;
    for (int i = 1; i < (1 << n); i++) {
      int xorr = 0;
      for (int j = 0; j < n; j++) {
        int msk = (1 << j);
        if ((i & msk) != 0) {
          xorr = (a[j] ^ xorr);
        }
      }
      s += xorr;
    }
    return s;
  }
};

int main() {}
