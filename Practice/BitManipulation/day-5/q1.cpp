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
  string s;
  cin >> s;
  s += '1';
  int n = s.size();
  int l_pos = n - 1;
  while (l_pos >= 0 && s[l_pos] == '1') {
    l_pos--;
  }
  if (l_pos == -1) {
    cout << 0 << "\n";
    return;
  }
  l_pos++;
  int ans = 0;
  for (int i = l_pos - 1; i >= 0; i--) {
    if (s[i] == '1') {
      ans += l_pos - i;
      l_pos--;
    }
  }
  cout << ans << "\n";
}

int32_t main() {
  auto begin = std::chrono::high_resolution_clock::now();
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;

  cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    Solve();
  }
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed =
      std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
  cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
  return 0;
}