#include <iostream>
using namespace std;

#include <bits/stdc++.h>
#define lli long long int

/*     Principle of exlusion and inclusion :
 * finding count of the all (unique) numbers that are divisible by every element
 * of vector till x
 * Example: x = 10 , v = {2,3}
 * output : cnt = 7  (2 3 4 6 8 9 10)
 */

int lcm(int a, int b) { return (a / __gcd(a, b) * b); }

int inclusion_exclusion(vector<int> v, int x) {
  int n = (int)v.size();
  int ans = 0;
  for (int i = 1; i < (1 << n); i++) {
    int lcmm = 1;
    for (int j = 0; j < n; j++) {
      if (i & (1 << j))
        lcmm = lcm(lcmm, v[j]);
    }
    if (__builtin_popcount(i) & 1)
      ans += (x / lcmm);
    else
      ans -= (x / lcmm);
  }
  return ans;
}

int main() {
  int ans = inclusion_exclusion({2, 3, 5}, 20);
  cout << ans << "\n";
}
