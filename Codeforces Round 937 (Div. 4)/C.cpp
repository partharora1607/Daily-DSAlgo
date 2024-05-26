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
  int h, m;
  char ch;
  cin >> h >> ch >> m;

  bool am = true;
  if (h >= 12)
    am = false;
  if (h > 12)
    h -= 12;
  if (h == 0)
    h = 12;

  cout << (h < 10 ? "0" : "") << h << ":" << (m < 10 ? "0" : "") << m
       << (am == true ? " AM" : " PM") << "\n";
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