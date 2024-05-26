#include <iostream>
using namespace std;

#include <bits/stdc++.h>
#define lli long long int

class Solution {
public:
  vector<int> sortByBits(vector<int> &a) {
    sort(a.begin(), a.end(), [&](auto &x, auto &y) {
      return __builtin_popcount(x) < __builtin_popcount(y);
    });
  }
};

int main() {}
