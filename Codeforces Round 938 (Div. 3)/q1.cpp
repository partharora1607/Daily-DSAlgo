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
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a(n), b(m);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  unordered_map<int, int> mp;
  for (int i = 0; i < m; i++) {
    cin >> b[i];
    mp[b[i]]++;
  }
  unordered_map<int, int> mp2;
  int ans = 0, cnt = 0;
  for (int i = 0; i < m; i++) {
    if (mp2.count(a[i]) == 0 && mp.count(a[i])) {
      mp2[a[i]]++;
      cnt++;
    }
  }
  if (cnt >= k)
    ans++;
  for (int i = m; i < n; i++) {
    if (mp2.count(a[i - m])) {
      if (--mp2[a[i - m]] == 0) {
        mp2.erase(a[i - m]);
        cnt--;
      }
    }
    if (mp2.count(a[i]) == 0 && mp.count(a[i])) {
      mp2[a[i]]++;
      cnt++;
    }
    if (cnt >= k)
      ans++;
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