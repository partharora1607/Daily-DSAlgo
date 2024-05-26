#include <bits/stdc++.h>
using namespace std;

#define int long long
#define lli long long int
#define inf (int)1e18
#define INF LLONG_MAX
#define f first
#define s second

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

vector<int> dp;

void helper() {
  vector<int> v = {11,    11 * 11,   11 * 11 * 11, 11 * 11 * 11 * 11,
                   111,   111 * 111, 101,          101 * 101,
                   1111,  1101,      1011,         1001,
                   11111, 11101,     11011,        10111,
                   11001, 10011,     10001};

  for (int i = 0; i < v.size(); i++) {
    for (int j = i + 1; j < v.size(); j++) {
      string s = to_string(v[i]), s1 = to_string(v[j]);
      if (s.size() + s1.size() - 1 > 6)
        continue;
      int val = v[i] * v[j];
      v.push_back(val);
    }
  }

  dp = v;
}

void Solve() {
  int n;
  cin >> n;
  while (n % 10 == 0) {
    n /= 10;
  }
  if (n == 1) {
    cout << "Yes"
         << "\n";
    return;
  }
  int cnt = count(dp.begin(), dp.end(), n);
  if (cnt >= 1) {
    cout << "Yes"
         << "\n";
  } else {
    cout << "No"
         << "\n";
  }
}

int32_t main() {
  auto begin = std::chrono::high_resolution_clock::now();
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  helper();
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