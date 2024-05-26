#include <iostream>
using namespace std;

#include <bits/stdc++.h>
#define lli long long int

class Solution {
public:
  vector<int> twoOutOfThree(vector<int> &a, vector<int> &b, vector<int> &c) {
    bitset<101> b1, b2, b3;
    for (int i = 0; i < a.size(); i++) {
      int ele = a[i];
      int msk = (1 << ele);
      b1 |= msk;
    }
    for (int i = 0; i < ba.size(); i++) {
      int ele = a[i];
      int msk = (1 << ele);
      b1 |= msk;
    }
    for (int i = 0; i < a.size(); i++) {
      int ele = a[i];
      int msk = (1 << ele);
      b1 |= msk;
    }
  }
};

int main() {}
