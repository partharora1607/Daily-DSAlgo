#include <iostream>
using namespace std;

#include <bits/stdc++.h>
#define lli long long int

// Method - 2 (checking each bit)
// Time complexity : 0(n) space : 0(1)
class Solution {
public:
  int minOperations(vector<int> &a, int k) {
    int cnt = 0;
    for (int i = 0; i < 32; i++) {
      int msk = (1 << i);
      int x = 0;
      for (int j = 0; j < a.size(); j++) {
        x ^= (a[j] & msk);
      }
      if ((k & msk) != x)
        cnt++;
    }
    return cnt;
  }
};

// Method - 1 (xor will find diff bits)
// Time Complexity : 0(n) space 0(1);

class Solution {
public:
  int minOperations(vector<int> &a, int k) {
    int x = 0;
    for (int i = 0; i < a.size(); i++) {
      x ^= a[i];
    }
    x ^= k;
    int setBits = __builtin_popcount(x);
    return setBits;
  }
};

int main() {}
