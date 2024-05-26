#include <iostream>
using namespace std;

#include <bits/stdc++.h>
#define lli long long int
class Solution {
public:
  int minimumSubarrayLength(vector<int> &a, int k) {
    int ans = INT_MAX;
    for (int i = 0; i < a.size(); i++) {
      int xorr = a[i];
      if (xorr >= k)
        ans = min(ans, 1);
      for (int j = i + 1; j < a.size(); j++) {
        xorr |= a[j];
        if (xorr >= k)
          ans = min(ans, j - i + 1);
      }
    }
    return ans == INT_MAX ? -1 : ans;
  }

  int main() {
    vector<int> a = {1, 2, 3};
    int ans = minimumSubarrayLength(a, 2);
    cout << ans << endl;
  }
