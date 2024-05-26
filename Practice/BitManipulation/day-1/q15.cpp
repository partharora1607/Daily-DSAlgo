#include <iostream>
using namespace std;

#include <bits/stdc++.h>
#define lli long long int

// sum of bit difference

int sumBitDifference(vector<int> &a) {
  int ans = 0;
  for (int i = 0; i < 32; i++) {
    int msk = (1 << i);
    int cnt1 = 0, cnt0 = 0;
    for (int j = 0; j < a.size(); j++) {
      if ((msk & a[j]))
        cnt1++;
      else
        cnt0++;
    }
    ans += (cnt1 * cnt0 * 2);
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  int ans = sumBitDifference(a);
  cout << ans << "\n";
  return 0;
}
