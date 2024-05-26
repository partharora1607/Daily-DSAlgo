#define ll long long
class Solution {
public:
  ll denomination(vector<int> &coins, ll x) {
    ll n = coins.size();
    ll cnt = 0;
    for (ll i = 1; i < (1 << n); i++) {
      ll lcmm = 1;
      for (ll j = 0; j < n; j++) {
        if (i & (1 << j)) {
          lcmm = lcm(lcmm, coins[j]);
        }
      }
      if (__builtin_popcount(i) & 1)
        cnt += x / lcmm;
      else
        cnt -= x / lcmm;
    }
    return cnt;
  }

  long long findKthSmallest(vector<int> &coins, int k) {
    ll l = 1, r = 1e11, ans = 0;
    while (l <= r) {
      ll m = (l + r) / 2;
      ll cnt = denomination(coins, m);
      if (cnt < k) {
        l = m + 1;
      } else {
        ans = m;
        r = m - 1;
      }
    }
    return ans;
  }
};