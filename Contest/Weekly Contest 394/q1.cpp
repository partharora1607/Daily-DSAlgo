#include <iostream>
using namespace std;

#include <bits/stdc++.h>
#define lli long long int

class Solution {
public:
  vector<int> twoOutOfThree(vector<int> &a, vector<int> &b, vector<int> &c) {
    int n1, n2, n3;
    n1 = n2 = n3 = 0;
    for (int i = 0; i < a.size(); i++)
      n1 |= a[i];
    for (int i = 0; i < a.size(); i++)
      n2 |= b[i];
    for (int i = 0; i < a.size(); i++)
      n3 |= c[i];
    int val = (n1 & n2) | (n1 & n3) | (n2 & n3);
    vector<int> res;
    while (val) {
      int rmsb = (val & -val);
      res.push_back(rmsb);
      val ^= rmsb;
    }
    return res;
  }
};

int main() {}
