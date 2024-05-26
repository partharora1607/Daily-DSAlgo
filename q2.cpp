#include <bits/stdc++.h>
using namespace std;

#define int long long
#define lli long long int
#define inf (int)1e18
#define INF LLONG_MAX
#define f first
#define s second

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  for (int j = m - 2; j >= 0; j--) {
    a[n - 1][j] = __gcd(a[n - 1][j], a[n - 1][j + 1]);
  }
  for (int i = n - 2; i >= 0; i--) {
    a[i][m - 1] = __gcd(a[i][m - 1], a[i + 1][m - 1]);
  }

  for (int i = n - 2; i >= 0; i--) {
    for (int j = m - 2; j >= 0; j--) {
      int val1 = __gcd(a[i][j], a[i + 1][j]);
      int val2 = __gcd(a[i][j], a[i][j + 1]);
      a[i][j] = max(val1, val2);
    }
  }

  cout << a[0][0] << "\n";
}

int32_t main() {
  auto begin = std::chrono::high_resolution_clock::now();
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;

  cin >> t;
  for (int i = 1; i <= t; i++) {
    // cout << "Case #" << i << ": ";
    Solve();
  }
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed =
      std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
  return 0;
}