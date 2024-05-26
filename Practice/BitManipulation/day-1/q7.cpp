#include <iostream>
using namespace std;

#include <bits/stdc++.h>
#define lli long long int

// minimum no of steps to 1;

int steps(int n) {
  if (n == 1)
    return 0;
  vector<int> dp(n + 1);
  dp[1] = 0;
  dp[0] = 0;
  for (int i = 2; i <= n; i++) {
    if (i % 2 == 0)
      dp[i] = 1 + dp[i / 2];
    else
      dp[i] = 2 + min(dp[(i + 1) / 2], dp[(i - 1) / 2]);
  }
  return dp[n];
}

int main() {
  int n;
  cin >> n;
  int cnt = steps(n);
  cout << cnt << "\n";
  return 0;
}
