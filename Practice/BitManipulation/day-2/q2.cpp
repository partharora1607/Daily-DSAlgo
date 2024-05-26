#include <iostream>
using namespace std;

#include <bits/stdc++.h>
#define lli long long int

class Solution {
public:
  int xorOperation(int n, int start) {
    int ans = 0;
    for (int i = 0; i < n; i++)
      ans ^= (start + 2 * i);
    return ans;
  }
};

int main() {}
