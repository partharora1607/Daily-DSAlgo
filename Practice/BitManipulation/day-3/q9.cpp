#include <iostream>
using namespace std;

#include <bits/stdc++.h>
#define lli long long int

class Solution {
public:
  bool hasTrailingZeros(vector<int> &a) {
    int cnt = 0;
    for (auto ele : a) {
      if (!(ele & 1))
        cnt++;
    }
    return cnt > 1;
  }
};

int main() {}
