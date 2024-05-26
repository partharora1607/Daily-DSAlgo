#include <iostream>
using namespace std;

#include <bits/stdc++.h>
#define lli long long int

class Solution {
public:
  int minBitFlips(int start, int goal) {
    int v = (start ^ goal);
    return __builtin_popcount(v);
  }
};

int main() {}
