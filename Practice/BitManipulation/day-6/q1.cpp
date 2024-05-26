#include <iostream>
using namespace std;

#include <bits/stdc++.h>
#define lli long long int

class Solution {
public:
  string addBinary(string a, string b) {
    if (b.size() > a.size())
      swap(a, b);
    while (b.size() < a.size()) {
      b = "0" + b;
    }
    string res;
    int cry = 0;
    for (int i = a.size(); i >= 0; i--) {
      int v = a[i] - '0' + b[i] - '0' + cry;
      if (v == 3) {
        cry = 1;
        res = "1" + res;
      } else if (v == 2) {
        cry = 1;
        res = "0" + res;
      } else if (v == 1) {
        cry = 0;
        res = "1" + res;
      } else {
        cry = 0;
        res = "0" + res;
      }
    }
    if (cry == 1)
      res = "1" + cry;
    return res;
  }
};

int main() {}
