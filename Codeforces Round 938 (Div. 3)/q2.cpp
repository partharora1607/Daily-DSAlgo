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
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int i = 0, j = n - 1;
  int sunk = 0; // Count of ships sunk
  while (i <= j && k > 0) {
    if (a[i] < a[j]) {
      if (k >= 2 * a[i] - 1) {
        k -= 2 * a[i] - 1;
        i++;
        sunk++; // Increment sunk ships count
      } else {
        cout << n - sunk << endl; // Remaining unsunk ships
        return;
      }
    } else if (a[i] > a[j]) {
      if (k >= 2 * a[j] - 1) {
        k -= 2 * a[j] - 1;
        j--;
        sunk++; // Increment sunk ships count
      } else {
        cout << n - sunk << endl; // Remaining unsunk ships
        return;
      }
    } else { // a[i] == a[j]
      if (i != j) {
        int sameDurability = 0; // Count ships with same durability
        while (i < j && a[i] == a[j]) {
          sameDurability++;
          i++;
        }
        if (sameDurability % 2 == 0) {
          cout << n - sunk << endl; // Remaining unsunk ships
          return;
        } else {
          if (k >= 2 * a[i] - 1) {
            k -= 2 * a[i] - 1;
            sunk += sameDurability + 1; // Increment sunk ships count
          } else {
            cout << n - sunk << endl; // Remaining unsunk ships
            return;
          }
        }
      } else { // i == j
        if (k >= a[i]) {
          cout << n - sunk - 1
               << endl; // Remaining unsunk ships excluding the single ship
          return;
        } else {
          cout << n - sunk << endl; // Remaining unsunk ships
          return;
        }
      }
    }
  }
  cout << n - sunk << endl; // Remaining unsunk ships
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