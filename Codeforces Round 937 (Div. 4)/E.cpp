#include <bits/stdc++.h>
using namespace std;

#define int long long
#define lli long long int
#define inf (int)1e18
#define INF LLONG_MAX
#define f first
#define s second

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

bool check(string str, string s) {
  int n1 = str.size(), n2 = s.size();
  if (n2 % n1 != 0)
    return false;
  while (str.size() < s.size()) {
    str += str;
  }
  int cnt = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] != str[i])
      cnt++;
  }
  return cnt == 0 || cnt == 1 || cnt == n2 / n1;
}

void Solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int ans = n;
  for (int i = 0; i < n / 2; i++) {
    string str = s.substr(0, i + 1);
    string ok = s.substr(i + 1);
    bool find = check(str, ok);
    if (find) {
      ans = str.size();
      cout << ans << "\n";
      return;
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