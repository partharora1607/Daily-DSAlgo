#include <iostream>
using namespace std;

#include <bits/stdc++.h>
#define lli long long int

class Solution {
public:
  int findKOr(vector<int> &a, int k) {
    int ans = 0, n = a.size();
    for (int i = 0; i < 32; i++) {
      int msk = (1 << i), cnt = 0;
      for (int j = 0; j < n; j++) {
        if ((a[j] & msk) != 0)
          cnt++;
      }
      if (cnt >= k)
        ans |= msk;
    }
    return ans;
  }
};

int main() {}
