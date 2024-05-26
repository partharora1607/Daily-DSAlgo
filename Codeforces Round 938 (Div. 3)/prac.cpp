#include <iostream>
using namespace std;

#include <bits/stdc++.h>
#define lli long long int

int main() {
  int n = 3;
  vector<vector<int>> dp(n, vector<int>(n));
  dp[0][0] = 1;
  int d = 3, c = 2;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (j + 1 < n)
        dp[i][j + 1] = dp[i][j] + d;
      if (i + 1 < n)
        dp[i + 1][j] = dp[i][j] + c;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }
}
